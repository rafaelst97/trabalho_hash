# trabalho_hash
Trabalho de tabelas hash de 2021

Você(s) precisa(m) implementar um programa (peso 2) que seja capaz de contabilizar a
frequência que as palavras aparecem em um determinado texto.

Para isso, Tabela Hash deve ser utilizada como estrutura de armazenamento das palavras,
com a estratégia de tratamento de colisão baseada em “Endereçamento Aberto”.

Operações obrigatórias para a tabela hash:

• Inserir;

• Remover;

• Buscar;

• Imprimir;

• Calcular Percentual de Ocupação; e

• 3 funções de hashing.

O algoritmo base para o programa é o seguinte:

1. Leia uma palavra do arquivo;

2. Insira na tabela;

a. Se a palavra não existir na tabela, insira-a na posição devida;

b. Se a palavra existir, incremente a frequência (número de vezes que a palavra
aparece)

3. Repita os passos 1 e 2 até não ter mais nenhuma palavra para ser lida no arquivo
de texto (TXT).

4. Exiba as informações sobre: (1) número de palavras do texto; (2) tamanho da
tabela; (3) a ocupação; (4) número de colisões; e (5) função de hashing adotada.

O texto a ser processado deve ser lido de um arquivo de texto (TXT), o qual você utilizará
para realizar diferentes testes (texto pequeno [até 20 palavras], médio [até 250 palavras]
e grande [até 1000 palavras]). O objetivo principal do trabalho é você implementar a
estrutura de tabela hash com endereçamento aberto, testar diferentes “funções de hash”
e analisar os resultados.

O critério a ser utilizado para o cálculo do endereço (função de hashing) será definido por
você e deve tomar como base (entrada) a “palavra lida”, portanto, investigue estratégias
que gerem menos colisões. Implemente 3 funções de hash distintas para compará-las.

Para não ter um resultado “viciado” (com viés), você deverá testar textos que possuam
diferenças entre si (não só no número de palavras, mas em quais palavras contém). 
