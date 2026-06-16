# Sistema Simples de Vendas e Controle de Estoque
Projeto desenvolvido para a disciplina de **Programação Orientada a Objetos**, com o objetivo de simular um sistema simples de vendas, cadastro de clientes, funcionários e produtos, além do controle de estoque e registro de vendas.
## Descrição
O sistema foi projetado para automatizar operações essenciais de uma loja, permitindo:
- login de clientes e funcionários
- cadastro e gerenciamento de clientes
- cadastro e gerenciamento de produtos
- cadastro e gerenciamento de funcionários
- registro de vendas
- controle de pagamento
- devolução de vendas
- controle de suspensão de clientes inadimplentes
- persistência de dados em arquivos `.dat`
O sistema funciona em modo texto, por meio de menus no terminal.
## Funcionalidades
### Clientes
- criar conta de cliente
- login de cliente
- visualizar dados cadastrais
- editar dados
- listar clientes
- desativar cliente
- listar clientes suspensos
- visualizar compras realizadas
### Funcionários
- login de funcionário
- cadastro de funcionários
- listagem de funcionários
- distinção entre funcionário comum e gerente
### Produtos
- cadastro de produtos
- listagem de produtos
- edição de produtos
- exclusão lógica de produtos
- controle de estoque
- listagem de produtos sem estoque
### Vendas
- registro de venda
- adição de itens à venda
- cálculo automático do total
- registro de pagamento
- registro de devolução
- listagem de vendas
- visualização de compras por cliente
## Regras de negócio
- qualquer pessoa que queira comprar precisa estar cadastrada como cliente
- usuários não são excluídos fisicamente, apenas desativados
- apenas funcionários gerentes podem gerenciar produtos e funcionários
- clientes suspensos não podem realizar compras
- uma venda sem pagamento gera suspensão de 15 dias para o cliente
- após o prazo da suspensão, o cliente volta a poder comprar
- a devolução de uma venda devolve os itens ao estoque
- o sistema cria um gerente padrão automaticamente caso não existam funcionários cadastrados
## Estrutura do projeto
```text
src/
└── br/
    └── vendas/
        ├── model/
        │   ├── Usuario.java
        │   ├── Cliente.java
        │   ├── Funcionario.java
        │   ├── Produto.java
        │   ├── ItemVenda.java
        │   └── Venda.java
        ├── util/
        │   └── Persistencia.java
        └── view/
            └── Menu.java
Classes principais
Usuario
Classe abstrata base do sistema. Contém informações comuns como:

nome
cpf
login
email
senha
status de ativação
Cliente
Herda de Usuario e adiciona:

id
endereço
telefone
suspensão
data de fim da suspensão
Funcionario
Herda de Usuario e adiciona:

id
indicador de gerente
Produto
Representa os produtos da loja, contendo:

id
nome
descrição
categoria
quantidade em estoque
preço
ItemVenda
Representa cada item de uma venda, contendo:

produto
quantidade
subtotal calculado
Venda
Representa a venda realizada no sistema, contendo:

id
data da venda
status de pagamento
status de devolução
cliente
funcionário
lista de itens
Persistencia
Responsável por salvar e carregar os dados em arquivos .dat.

Menu
Classe principal do sistema, responsável pela interação com o usuário via terminal.

Persistência de dados
Os dados do sistema são armazenados localmente em arquivos:

clientes.dat
produtos.dat
funcionarios.dat
vendas.dat
Esses arquivos permitem manter as informações entre diferentes execuções do programa.

Tecnologias utilizadas
Java
Programação Orientada a Objetos
Serialização de objetos
Persistência em arquivos
Interface via terminal
Como executar
Pré-requisitos
Java instalado
compilador Java disponível no ambiente
Compilação
No terminal, dentro da pasta do projeto, compile os arquivos .java com um comando compatível com a estrutura do projeto.

Exemplo:

bash


javac -d bin src/br/vendas/model/*.java src/br/vendas/util/*.java src/br/vendas/view/*.java
Execução
Depois de compilar, execute a classe principal:

bash


java -cp bin br.vendas.view.Menu
Login inicial do sistema
Caso não exista nenhum funcionário cadastrado, o sistema cria automaticamente um gerente padrão com os seguintes dados:

text


Login: admin
Senha: admin
Exemplo de uso
iniciar o sistema
entrar como funcionário
acessar com o login do gerente padrão
cadastrar produtos
cadastrar clientes
registrar vendas
registrar pagamento ou inadimplência
consultar vendas, produtos e clientes
Equipe
Gerislan da Silva Araujo
José Veríssimo de Oliveira Queiroz
Paulo Henrique Souza Lima
Disciplina
PEX0130 - Programação Orientada a Objetos
Universidade Federal Rural do Semi-Árido - Campus Pau dos Ferros