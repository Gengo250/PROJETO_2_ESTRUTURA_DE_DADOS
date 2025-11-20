# Projeto 2 – Organização e Análise de Dados de Vendas (ABB em C)

Sistema em **linguagem C** desenvolvido para a disciplina **Estrutura de Dados (Prática)** do curso de **Engenharia de Computação**, com o objetivo de organizar e analisar dados de vendas utilizando **Árvore Binária de Busca (ABB)** como estrutura principal.

O projeto simula o sistema interno de uma empresa, permitindo cadastrar vendas, consultar o histórico de forma ordenada e extrair estatísticas importantes de faturamento.

---
## 📚 Contexto acadêmico

Este projeto faz parte do **2º Projeto Avaliativo – Organização e Análise de Dados de Vendas**, na disciplina de **Estrutura de Dados (Prática)** do curso de Engenharia de Computação, com foco em aplicar conceitos de árvores binárias a um problema real de organização de vendas.

---

## 🎯 Objetivos do sistema

- Armazenar vendas em uma **Árvore Binária de Busca**, ordenadas pelo **ID da venda**.  
- Permitir **consultas rápidas e ordenadas** sobre as transações.  
- Auxiliar na **análise de desempenho de vendas**, destacando valores altos/baixos e estatísticas gerais.  

---


## ✅ Funcionalidades implementadas

1. **Inserir uma nova venda**  
   - Cadastro completo de uma venda contendo:
     - ID da venda (gerado aleatoriamente entre 1000 e 9999, sem repetição)  
     - Nome do cliente  
     - Nome do vendedor  
     - Matrícula do vendedor (por exemplo, `12345`)  
     - Data da transação (dia, mês, ano)  
     - Valor da transação (duas casas decimais)  
   - Inserção na ABB de acordo com as regras vistas em aula (ordenada pelo ID).

2. **Listar todas as vendas**  
   - Impressão de todas as vendas armazenadas na ABB.  
   - Opção de listagem em **ordem crescente** ou **decrescente** de ID.  
   - Formato de saída em tabela, com o cabeçalho:
     ```text
     ID | Vendedor | Matrícula | Cliente | Data de Transação | Valor (R$)
     ```

3. **Buscar vendas de um determinado vendedor**  
   - Busca por **nome do vendedor** ou por **matrícula**.  
   - Exibição do cabeçalho:
     ```text
     Vendedor: <nome do vendedor>
     Matrícula: <matrícula do vendedor>
     ```
   - Tabela de resultados:
     ```text
     ID | Cliente | Data de Transação | Valor (R$)
     ```

4. **Listar vendas acima ou abaixo de um valor definido**  
   - Usuário informa um valor de referência.  
   - O sistema lista as vendas **acima** ou **abaixo** desse valor, conforme a opção escolhida.  
   - Tabela com o mesmo padrão de cabeçalho da listagem geral.

5. **Exibir estatísticas**  
   - Número total de vendas cadastradas.  
   - Soma total do faturamento (soma dos valores das transações).  
   - Possibilidade de extensão para análises estatísticas adicionais.

6. **Remoção de uma venda**  
   - Remoção de uma venda a partir do **ID**, seguindo as regras clássicas de remoção em ABB:
     - Nó folha  
     - Nó com um filho  
     - Nó com dois filhos (substituição por sucessor/pré-sucessor)  

7. **Finalização do sistema**  
   - Opção para encerrar o programa de forma segura, liberando a memória utilizada pela árvore.

---

## 🧱 Estruturas de dados principais

- `struct Data`  
  Representa a data da transação: dia, mês e ano.

- `struct Sistema`  
  Estrutura que representa uma venda, contendo:
  - `int ID`
  - `char Cliente[50]`
  - `char Vendedor[50]`
  - `int matricula_do_vendedor`
  - `float valor_transacao`
  - `Data data_transacao`

- `struct NoArv`  
  Nó da **Árvore Binária de Busca**, contendo:
  - `Sistema sistema`  
  - Ponteiros para filho esquerdo e direito.

- `struct Arv`  
  Estrutura que encapsula a raiz da árvore:
  - `NoArv *raiz;`

---

## 📁 Estrutura do repositório

- `main.c`  
  - Função `main`  
  - Exibição do menu principal  
  - Chamada das funções de cadastro, listagem, busca, estatísticas e remoção.

- `biblioteca.h`  
  - Declaração das estruturas (`Data`, `Sistema`, `NoArv`, `Arv`)  
  - Protótipos das funções de:
    - Criação e inicialização da árvore  
    - Inserção de nós (vendas)  
    - Percursos (in-ordem, etc.)  
    - Busca de vendas  
    - Listagens filtradas  
    - Cálculo de estatísticas  
    - Remoção de nós  
    - Liberação de memória

- `SEGUNDO PROJETO.pdf`  
  - Enunciado oficial do projeto, com todas as regras e requisitos funcionais.

---

## 🛠️ Tecnologias e conceitos utilizados

- Linguagem **C** (compilação via GCC / Code::Blocks / outro compilador compatível).  
- **Árvore Binária de Busca (ABB)** como estrutura central.  
- **Alocação dinâmica de memória** com ponteiros.  
- **Modularização** do código com uso de arquivo de cabeçalho (`.h`).  
- Manipulação de:
  - Strings (`char[]`)  
  - Datas  
  - Geração de números aleatórios para IDs.

---

## 🧭 Fluxo de uso do sistema

1. Ao iniciar o programa, o usuário visualiza um menu com as opções:
   - Inserir nova venda  
   - Listar vendas  
   - Buscar por vendedor  
   - Listar por faixa de valor  
   - Exibir estatísticas  
   - Remover venda  
   - Sair  

2. O usuário escolhe uma opção digitando o número correspondente.  

3. O sistema realiza as operações na ABB e mostra os resultados em formato de tabela no terminal.  

4. O usuário pode repetir as operações até escolher a opção de **finalizar**.

---

## 👥 Equipe e contribuições

Projeto desenvolvido em time, com foco em colaboração, divisão de responsabilidades e boas práticas de código.

**Integrantes:**

[![GitHub - Gengo250](https://img.shields.io/badge/GitHub-Gengo250-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Gengo250)
[![GitHub - LuccasZibordi](https://img.shields.io/badge/GitHub-LuccasZibordi-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/LuccasZibordi)
[![GitHub - JoaoVitorBomboGuimaraes](https://img.shields.io/badge/GitHub-JoaoVitorBomboGuimaraes-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/JoaoVitorBomboGuimaraes)
[![GitHub - GuiMasca](https://img.shields.io/badge/GitHub-GuiMasca-181717?style=for-the-badge&logo=github&logoColor=white)](https://github.com/GuiMasca)


Cada integrante contribuiu em diferentes etapas, como:
- definição das estruturas de dados,  
- implementação das funções de árvore,  
- montagem do menu e fluxo principal,  
- testes e validação das funcionalidades conforme o enunciado do projeto.
- montagem do relatório pedido

---


