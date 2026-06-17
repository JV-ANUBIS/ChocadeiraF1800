# Sistema Simples de Vendas e Controle de Estoque
Projeto desenvolvido para a disciplina de **Programação Orientada a Objetos**, com foco na aplicação de conceitos como **herança, encapsulamento, composição, serialização e manipulação de coleções**, por meio da implementação de um sistema de vendas em ambiente de console.
O sistema permite o gerenciamento de **clientes, funcionários, produtos e vendas**, além de realizar **controle de estoque**, **registro de pagamentos**, **devoluções** e **suspensão temporária de clientes inadimplentes**.
---
## Visão geral
O projeto simula o funcionamento básico de uma loja, oferecendo operações essenciais para cadastro, consulta e controle das entidades do sistema.
Entre os principais recursos implementados, estão:
- autenticação de clientes e funcionários
- diferenciação entre funcionários comuns e gerentes
- cadastro e manutenção de clientes
- cadastro e gerenciamento de produtos
- cadastro e gerenciamento de funcionários
- registro de vendas com múltiplos itens
- cálculo automático do valor total da venda
- controle de pagamento
- devolução de vendas com atualização do estoque
- persistência de dados em arquivos `.dat`
Toda a interação é realizada por meio de **menus no terminal**, organizando o fluxo de uso do sistema de forma simples e objetiva.
---
## Funcionalidades
### Clientes
- criar conta de cliente
- realizar login
- visualizar dados cadastrais
- editar informações
- listar clientes cadastrados
- desativar cliente
- listar clientes suspensos
- visualizar compras realizadas
### Funcionários
- realizar login
- cadastrar funcionários
- listar funcionários
- distinguir funcionários comuns de gerentes
### Produtos
- cadastrar produtos
- listar produtos
- editar produtos
- excluir logicamente produtos
- adicionar e remover estoque
- listar produtos sem estoque
### Vendas
- registrar vendas
- adicionar itens à venda
- calcular subtotal por item
- calcular total da venda
- registrar pagamento
- registrar devolução
- listar vendas
- listar compras de um cliente
---
## Regras de negócio
O sistema segue as seguintes regras:
- qualquer pessoa que deseje comprar deve estar cadastrada como cliente
- usuários não são removidos definitivamente, apenas desativados
- apenas funcionários com perfil de gerente podem gerenciar produtos e funcionários
- clientes suspensos não podem realizar novas compras
- vendas não pagas geram suspensão de 15 dias para o cliente responsável
- após o prazo da suspensão, o cliente volta a ficar apto para comprar
- devoluções retornam os produtos ao estoque
- caso não exista nenhum funcionário cadastrado, o sistema cria automaticamente um gerente padrão
---
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
Organização das classes
Usuario
Classe abstrata base do sistema. Reúne os atributos e comportamentos comuns aos usuários:

nome
cpf
login
email
senha
status de ativação
Cliente
Especialização de Usuario que representa os clientes da loja. Possui:

id
endereço
telefone
status de suspensão
data de fim da suspensão
Funcionario
Especialização de Usuario responsável por representar os funcionários do sistema. Possui:

id
indicador de gerente
Produto
Representa os produtos comercializados pela loja, contendo:

id
nome
descrição
categoria
quantidade em estoque
preço
ItemVenda
Representa cada item associado a uma venda, contendo:

produto
quantidade
cálculo de subtotal
Venda
Representa uma venda registrada no sistema, contendo:

id
data da venda
status de pagamento
status de devolução
cliente
funcionário
lista de itens vendidos
Persistencia
Classe utilitária responsável por salvar e carregar os dados serializados em arquivos .dat.

Menu
Classe responsável pela execução principal do sistema e pela interação com o usuário por meio do terminal.

Persistência de dados
As informações do sistema são armazenadas em arquivos locais, permitindo que os dados permaneçam disponíveis entre diferentes execuções.

Arquivos utilizados:

clientes.dat
produtos.dat
funcionarios.dat
vendas.dat
Tecnologias e conceitos aplicados
Este projeto utiliza:

Java
Programação Orientada a Objetos
Herança
Encapsulamento
Composição
Serialização de objetos
Persistência em arquivos
Estruturas de repetição e decisão
Interface textual via terminal
Como executar
Pré-requisitos
Para executar o projeto, é necessário ter:

Java instalado
JDK configurado no ambiente, para compilação do projeto
Compilação
No terminal, dentro da raiz do projeto, compile os arquivos com um comando compatível com a estrutura de pacotes.

Exemplo:

bash


javac -d bin src/br/vendas/model/*.java src/br/vendas/util/*.java src/br/vendas/view/*.java
Execução
Após a compilação, execute a aplicação com:

bash


java -cp bin br.vendas.view.Menu
Acesso inicial
Se não existir nenhum funcionário cadastrado, o sistema cria automaticamente um gerente padrão com as seguintes credenciais:

text


Login: admin
Senha: admin
Exemplo de fluxo de uso
iniciar o sistema
entrar como funcionário
acessar com o login do gerente padrão
cadastrar produtos
cadastrar clientes
registrar vendas
registrar pagamento ou inadimplência
consultar clientes, produtos e vendas
Equipe
Gerislan da Silva Araujo
José Veríssimo de Oliveira Queiroz
Paulo Henrique Souza Lima
Disciplina
PEX0130 - Programação Orientada a Objetos
Universidade Federal Rural do Semi-Árido - Campus Pau dos Ferros

Considerações finais
Este projeto foi desenvolvido com finalidade acadêmica, buscando colocar em prática os principais fundamentos da Programação Orientada a Objetos em um cenário aplicado de vendas e controle de estoque.

Além de atender aos requisitos propostos, a implementação também serve como base para futuras melhorias, como ampliação das validações, refinamento da navegação por menus e evolução da organização interna do código.