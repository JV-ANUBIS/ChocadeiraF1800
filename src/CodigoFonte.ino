#include <LiquidCrystal.h>
#include <DHT.h>
#include <RTClib.h>

#define DHTPIN 13
#define DHTTYPE DHT22

#define RELEPIN A3
#define BUTTONPIN 8
#define OVOSCOPIAPIN 9
#define LED_LIGADA 10
#define LED_DESLIGADA 11
#define LED_UMIDADE A1

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
RTC_DS3231 rtc;

bool lampadasLigadas = false;
bool ovoscopiaLigada = false;
bool botaoAnterior = HIGH;

DateTime inicioIncubacao(2025, 8, 4, 15, 0, 0);

void setup() {
  lcd.begin(20, 4);
  dht.begin();

  if (!rtc.begin()) {
    lcd.setCursor(0, 0);
    lcd.print("Erro: RTC nao found");
    while (1);
  }

  pinMode(RELEPIN, OUTPUT);
  pinMode(OVOSCOPIAPIN, OUTPUT);
  pinMode(LED_LIGADA, OUTPUT);
  pinMode(LED_DESLIGADA, OUTPUT);
  pinMode(LED_UMIDADE, OUTPUT);
  pinMode(BUTTONPIN, INPUT_PULLUP);

  lcd.setCursor(0, 0);
  lcd.print("CHOCADEIRA F1800");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();
  DateTime agora = rtc.now();

  bool botaoAtual = digitalRead(BUTTONPIN);
  if (botaoAnterior == HIGH && botaoAtual == LOW) {
    ovoscopiaLigada = !ovoscopiaLigada;
    digitalWrite(OVOSCOPIAPIN, ovoscopiaLigada ? HIGH : LOW);
    delay(300);
  }
  botaoAnterior = botaoAtual;

  if (isnan(temperatura) || isnan(umidade)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no sensor DHT");
    delay(2000);
    return;
  }

  if (!lampadasLigadas && temperatura <= 37.0) {
    digitalWrite(RELEPIN, LOW);
    lampadasLigadas = true;
  }
  if (lampadasLigadas && temperatura >= 38.0) {
    digitalWrite(RELEPIN, HIGH);
    lampadasLigadas = false;
  }

  digitalWrite(LED_LIGADA, lampadasLigadas ? HIGH : LOW);
  digitalWrite(LED_DESLIGADA, lampadasLigadas ? LOW : HIGH);
  digitalWrite(LED_UMIDADE, (umidade < 55.0 || umidade > 65.0) ? HIGH : LOW);

  TimeSpan tempoPassado = agora - inicioIncubacao;
  int horasDesdeInicio = tempoPassado.totalseconds() / 3600;
  int minutosDesdeInicio = tempoPassado.totalseconds() / 60;
  int diasFaltando = max(0, 21 - tempoPassado.days());

  bool mostrarRotacao = (horasDesdeInicio > 0) && (horasDesdeInicio % 5 == 0) && ((minutosDesdeInicio % 300) < 30);

  lcd.setCursor(0, 0);
  lcd.print("Chocadeira F1800   ");

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura, 1);
  lcd.write(byte(223));
  lcd.print("C U:");
  lcd.print(umidade, 0);
  lcd.print("% F:");
  lcd.print(diasFaltando);
  lcd.print("D");

  lcd.setCursor(0, 2);
  lcd.print("LPD:");
  lcd.print(lampadasLigadas ? "L " : "D ");
  lcd.print("H:");
  if (agora.hour() < 10) lcd.print("0");
  lcd.print(agora.hour());
  lcd.print(":");
  if (agora.minute() < 10) lcd.print("0");
  lcd.print(agora.minute());

  lcd.setCursor(0, 3);
  if (mostrarRotacao) {
    lcd.print("ROTACIONE OS OVOS   ");
  } else {
    lcd.print("                    ");
  }

  delay(2000);
}
