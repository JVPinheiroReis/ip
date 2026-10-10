# Mini Projeto 02 - Central de Comunicações Alienígenas

## Identificação da Dupla

* **Integrante 1:** João Victor Pinheiro Reis
* **Integrante 2:** Gabriel Ramos Silva

---

## Instruções de Compilação e Execução

### Pré-requisitos

* Compilador C (`gcc` recomendado)
* Terminal Linux / Unix

### Compilação

Na raiz do projeto, execute:

```bash
gcc -Wall -Wextra src/mp02.c -o mp02
```

### Execução

Para executar o programa de forma interativa:

```bash
./mp02
```

---

## Visão Geral do Sistema

O programa implementa a **Central de Comunicações Alienígenas**, recebendo uma mensagem de texto inicial e aplicando uma sequência cumulativa de operações de transformação sobre ela.

### Fluxo de Execução na `main`

1. **Entrada da Mensagem:** A mensagem inicial de até 10.000 caracteres é lida da primeira linha via `scanf("%[^\n]%*c", s)`.
2. **Loop de Operações:** O programa entra em um laço infinito (`while(1)`), aguardando códigos de operação inteiros (`op`):
   * Se for `2` ou `5`, lê um valor inteiro adicional `n` como parâmetro antes de acionar a respectiva função.
   * Aciona a função correspondente através de um `switch(op)`, passando o ponteiro da string `s` para modificar seu estado atual.
3. **Término e Saída:** Ao receber `0`, encerra a execução imprimindo **exclusivamente a mensagem final resultante** com quebra de linha (`\n`), atendendo aos critérios de correção automatizada. Códigos não mapeados encerram o programa de imediato através da cláusula `default`.

---

## Decisões de Implementação

Conforme as restrições do projeto, não foi utilizada a biblioteca `<string.h>`; todas as manipulações de caracteres e controle de buffers foram desenvolvidos manualmente.

### Função Auxiliar

* **`get_string_size(char *s)`**: Substitui `strlen()`. Percorre a string até o caractere nulo `\0` para calcular e retornar seu comprimento exato.

### Funções Principais de Transformação

1. **`inverter(char *s)`** (Op. `1`):
   * Utiliza um vetor temporário `tmp` para armazenar os caracteres percorridos do final para o início da string, copiando o resultado de volta para o ponteiro original `s`.
2. **`deslocar(char *s, int n)`** (Op. `2`):
   * Aplica deslocamento circular em cada caractere alfanumérico.
   * Utiliza operadores de módulo (`n % 26` para letras maiúsculas/minúsculas e `n % 10` para números de 0 a 9) e trata os limites de borda da tabela ASCII (subtraindo ou somando o tamanho do intervalo), garantindo ciclicidade tanto para incrementos quanto para decrementos. Caracteres especiais permanecem inalterados.
   * **Prevenção de overflow:** Para evitar overflow aritmético no tipo `char` (que possui representação com sinal e limite superior de 127 na tabela ASCII), o cálculo do deslocamento e os ajustes de borda são executados em uma variável inteira auxiliar (`int c`), atribuindo o caractere de volta a `s[i]` apenas após a validação.
3. **`trocarParesImpares(char *s)`** (Op. `3`):
   * Percorre a string de 2 em 2 caracteres, realizando o swap entre posições adjacentes `s[i]` e `s[i+1]`.
   * Para strings de comprimento ímpar, o laço para em `size - 2`, preservando o último caractere em sua posição original.
4. **`inverterCaixa(char *s)`** (Op. `4`):
   * Alterna letras maiúsculas para minúsculas e vice-versa somando/subtraindo o offset `'a' - 'A'` da tabela ASCII.
5. **`rotacionar(char *s, int n)`** (Op. `5`):
   * Realiza a rotação circular de toda a mensagem com auxílio de um vetor temporário `tmp`.
   * **Tratamento de `n` (positivo e negativo):** Executa `n %= size` para normalizar deslocamentos maiores que o tamanho da string. Ao mapear o caractere para o novo índice `j = i + n`:
     * Se `j < 0` (rotação negativa/esquerda além do início), a nova posição é ajustada com `j += size`.
     * Se `j > size - 1` (rotação positiva/direita além do fim), a nova posição é ajustada com `j -= size`.
     * O caractere preservado do vetor temporário `tmp` é então posicionado em `s[j]`.
6. **`trocarMetades(char *s)`** (Op. `6`):
   * Troca a primeira metade da string pela segunda metade *in-place*.
   * O deslocamento do segundo bloco é calculado com `j = size - size / 2 + i`. Dessa forma, em mensagens com tamanho ímpar, o caractere central não é alterado e permanece exatamente no meio da string.
