# 🐣 Chocadeira F1800 — Controle Automático de Incubação

Projeto de TCC desenvolvido para automatizar o controle de temperatura, umidade e rotação de ovos em uma chocadeira artesanal utilizando Arduino, sensor DHT22 e módulo RTC DS3231.

---

## 📸 Galeria do Projeto

### Chocadeira finalizada — vista frontal fechada
![Frente fechada](assets/FrenteFechada.jpeg)

### Chocadeira finalizada — frente aberta com bandeja e sensor DHT22 visível
![Frente aberta](assets/FrenteDaChocadeiraAberta.jpeg)

### Vista frontal alternativa
![Frente alternativa](assets/FrenteDaChocadeira2.jpeg)

### Painel de controle — display LCD 20x4 e LEDs indicadores
![Display e LEDs](assets/Display.jpeg)

### Parte interna superior — lâmpadas, ventoinha e sensor DHT22 instalados
![Parte interna superior](assets/ParteInternaSuperior.jpeg)

### Parte interna com lâmpadas acesas
![Parte interna com luz](assets/ParteInternaComLuz.jpeg)

### Tampa superior aberta — vista dos soquetes e bandeja de rolagem
![Tampa superior aberta](assets/TampaSuperiorAberta.jpeg)

### Bandeja de rolagem — objeto para rolagem dos ovos isolado
![Objeto para rolagem](assets/ObjetoParaRolagem.jpeg)

### Lateral do circuito — Arduino, relé, fonte e fiação
![Lateral do circuito](assets/LateraldoCircuito.jpeg)

### Circuito montado — visão geral da eletrônica
![Circuito montado](assets/CircuitoMontado.jpeg)

### Circuito montado — visão alternativa
![Circuito montado 2](assets/CircuitoMontado2.jpeg)

### Em construção — fase inicial da montagem da frente
![Em construção](assets/FrenteEmConstrução.jpeg)

---

## 📋 Funcionalidades

- Monitoramento em tempo real de **temperatura** e **umidade**
- Controle automático do **relé** que aciona as lâmpadas e a ventoinha com histerese (liga em ≤37°C, desliga em ≥38°C)
- Exibição das informações em **display LCD 20x4**
- **Contagem regressiva** de dias até o fim da incubação (21 dias)
- Aviso de **rotação dos ovos** a cada 5 horas
- **LED indicadores** de estado das lâmpadas e alerta de umidade fora da faixa ideal
- **Ovoscopia** acionada por botão físico
- Verificação de erro no sensor DHT22 e no módulo RTC

---

## 🛠️ Hardware utilizado

| Componente | Descrição |
|---|---|
| Arduino Uno/Mega | Microcontrolador principal |
| DHT22 | Sensor de temperatura e umidade |
| RTC DS3231 | Módulo de relógio em tempo real |
| LCD 20x4 | Display de exibição |
| Módulo Relé | Acionamento das lâmpadas e ventoinha |
| LED Verde | Indica lâmpadas ligadas |
| LED Vermelho | Indica lâmpadas desligadas |
| LED Amarelo/Azul | Alerta de umidade fora da faixa |
| Botão | Acionamento da ovoscopia |
| Lâmpada de ovoscopia | Iluminação para inspeção dos ovos |
| Ventoinha | Circulação de ar interno |
| Fonte chaveada | Alimentação do sistema |

---

## 📌 Mapeamento de pinos

| Pino | Componente |
|---|---|
| 13 | DHT22 (dados) |
| A3 | Relé principal |
| 8 | Botão de ovoscopia |
| 9 | Lâmpada de ovoscopia |
| 10 | LED verde (lâmpadas ligadas) |
| 11 | LED vermelho (lâmpadas desligadas) |
| A1 | LED de alerta de umidade |
| 7, 6, 5, 4, 3, 2 | LCD (RS, E, D4, D5, D6, D7) |

---

## 📚 Bibliotecas necessárias

Instale pela Arduino IDE em **Sketch → Include Library → Manage Libraries**:

| Biblioteca | Autor |
|---|---|
| DHT sensor library | Adafruit |
| RTClib | Adafruit |
| LiquidCrystal | Built-in (já inclusa na IDE) |

---

## ⚙️ Como usar

1. Clone este repositório
2. Instale as bibliotecas listadas acima
3. Abra o arquivo `CodigoFonte/CodigoFonte.ino` na Arduino IDE
4. Ajuste a data e hora de início da incubação na linha:
   ```cpp
   DateTime inicioIncubacao(2025, 8, 4, 15, 0, 0);
   ```
5. Faça o upload para o Arduino
6. Conecte os componentes conforme o mapeamento de pinos acima

---

## 🌡️ Parâmetros de incubação

| Parâmetro | Faixa ideal |
|---|---|
| Temperatura | 37°C a 38°C |
| Umidade | 55% a 65% |
| Período de incubação | 21 dias |
| Rotação dos ovos | A cada 5 horas |

---

## 📁 Estrutura do repositório

```
chocadeira-f1800/
├── CodigoFonte/
│   └── CodigoFonte.ino
├── assets/
│   ├── FrenteFechada.jpeg
│   ├── FrenteDaChocadeiraAberta.jpeg
│   ├── FrenteDaChocadeira2.jpeg
│   ├── Display.jpeg
│   ├── ParteInternaSuperior.jpeg
│   ├── ParteInternaComLuz.jpeg
│   ├── TampaSuperiorAberta.jpeg
│   ├── ObjetoParaRolagem.jpeg
│   ├── LateraldoCircuito.jpeg
│   ├── CircuitoMontado.jpeg
│   ├── CircuitoMontado2.jpeg
│   └── FrenteEmConstrução.jpeg
└── README.md
```

---

## 👨‍💻 Autor

**José Veríssimo de Oliveira Queiroz**

Desenvolvido como Trabalho de Conclusão de Curso (TCC).
