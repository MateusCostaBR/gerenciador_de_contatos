# Gerenciador de Contatos em C

## Descrição
Este projeto consiste no desenvolvimento de um **Gerenciador de Contatos em linguagem C**, criado para a disciplina de **Laboratório de Programação** do curso de **Engenharia de Software**.

O sistema permite ao usuário realizar o gerenciamento de contatos através de um menu interativo no terminal. Entre as funcionalidades disponíveis estão o cadastro, listagem, busca, edição e exclusão de contatos, além da exibição de estatísticas sobre os dados armazenados.

O projeto utiliza conceitos fundamentais da programação em C, como **structs, funções, manipulação de strings, modularização do código e função recursiva**.

---

## Funcionalidades

O sistema possui as seguintes funcionalidades:

- Cadastrar novos contatos
- Listar todos os contatos cadastrados
- Buscar contatos pelo nome
- Editar informações de um contato
- Excluir contatos do sistema
- Exibir estatísticas dos contatos cadastrados

---

## Estrutura do Projeto

O projeto é dividido em arquivos para melhor organização:

- **main.c**  
Responsável pelo menu principal e controle da execução do programa.

- **contatos.c**  
Contém a implementação das funções responsáveis pelas operações do sistema.

- **contatos.h**  
Arquivo de cabeçalho que define a estrutura de dados e os protótipos das funções utilizadas no projeto.

---

## Tecnologias Utilizadas

- Linguagem **C**
- Compilador **Dev-C++**
- Manipulação de arquivos texto
- Estrutura de dados utilizando **struct**

---

## Integrantes do Grupo

**Mateus Silva Da Costa**  
Matrícula: 2510559  
Responsável principalmente pela implementação do arquivo **contatos.c**

**Cauã Fernandes Cardoso Ferreira**  
Matrícula: 2512330  
Responsável principalmente pelo desenvolvimento do arquivo **contatos.h e main.c**

**João Pedro Moreira Machado**  
Matrícula: 2512516  
Responsável por fazer a revisão do código, apontando possíveis erros

---

## Como executar no Dev-C++

1. Abra o **Dev-C++**.
2. Clique em **Arquivo → Novo → Projeto** e crie um **projeto em C**.
3. Depois que o projeto for criado, **apague o arquivo `main.c` que vem por padrão** no projeto.
4. No painel do projeto (lado esquerdo), clique com o **botão direito no nome do projeto** e selecione **Adicionar ao projeto → Novo arquivo** ou **Adicionar arquivo existente**.
5. Adicione os arquivos do projeto:
   - `main.c`
   - `contatos.c`
   - `contatos.h`
6. Você pode **copiar e colar o código** dentro dos novos arquivos criados no Dev-C++ ou **adicionar os arquivos diretamente** se já os tiver baixado.
7. Clique em **Executar → Compilar e Executar (F11)**.

O programa será compilado e executado normalmente.

---

## Objetivo do Projeto

O objetivo deste trabalho é aplicar na prática os conceitos aprendidos em sala de aula, como **modularização de programas, manipulação de estruturas, uso de funções recursivas e organização de código em múltiplos arquivos**.
