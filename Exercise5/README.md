# Atividade 5 - Mutex

Neste atividade, estudamos o Mutex nas threads, onde evita fraudes durante o execucao das threads.

Como vimos o codigo do exemplo (contagem), executando varios threads sem o mutex pode causar threads alternarios a dar execucao em primeiro, e depois o ultimo e, em menos chances, um de todos os threads podem nao executar. Com o Mutex, todos os threads estao em execucao de ordem certa e sem fraudes.

Nesse atividade, o codigo da atividade possui o Mutex que e recomendavel para executar todos os threads para evitar fraudes que afetam os threads, executando em ordem aleatorio em vez de completa (que esta no Mutex).

## Explicando o Codigo

O codigo possui comentarios em ingles para explicar melhor o uso do codigo, threads e execucao.

Esse codigo, possui dois funcoes, um para o uso de threads, e um para execucao.

- main - Pode ser usado para execucao do arquivo apos o compilacao.
- sumlines - Usado para threads, o funcao calcula e retorna o total de numeros de cada linha do matriz. Quando a proxima linha do matriz tem, a proxima thread a ser calculando e executada.

E possui seis variaveis:

- c - O numero inteiro que pode ser usado para contagem e para array do funcao sumlines.
- res - O numero inteiro total calculando a partir de numeros que estao na matriz.
- sarray - O numero inteiro que pode ser usado para o tamanho do matriz e para loops.
- arr - A matriz que guarda numeros.
- tarray - Um array que pode ser usado para guardar numero da cada linha do matriz que retorna apos execucao de thread.
- mutex - O Mutex que pode bloquear e desbloquear durante o execucao de thread para evitar fraudes.

#### O funcao main

Comecando a funcao main, o usuario insira o tamanho do matriz, onde retorna o tamanho do matriz N x N, onde N e um numero de que o usuario escreve. Apos o usuario digitar, aloca a memoria para criar dois arrays, um para guardar numeros da matriz, e um para guardar numeros onde retorna de threads um total de numeros de cada linha do matriz. Apos alocar a memoria, o usuario insira os numeros para guardar na matriz. Apos a entrada do usuario, cria um array de threads com o tamanho da linha do matriz. Um thread pode ser usado para calcular e retornar o total de numeros da cada linha do matriz. Caso a proxima linha do matriz possui numeros, o proximo thread e executando. Apos criacao de threads, comeca primeiro um thread que leia os numeros da primeira linha do matriz ate a ultima linha do matriz, usando o Mutex para ordenar de primeira para ultima linha do matriz corretamente. Apos o ultimo thread executado, imprima o numero total apos soma total de todos os numeros em uma matriz.

## Passo

Primeiro usar o comando 'make' para compilacao, executacao e limpacao. No terminal, para compilar o codigo, digite 'make', e depois do compilacao, digite 'make run' e, em execucao, digite o tamanho da matriz, como mostra o quatro que o usuario digite:

```C
3
4 9 3
-4 -1 5
-2 1 -9
```

E apos, o numero que pode ser guardando para matriz. Apos todos os numeros e sem vazio na matriz. Os threads executam com o Mutex para calcular. Apos todos os threads ja executados, o terminal imprima um soma total de numeros de todos os numeros em um matriz, como mostra o quatro:

```C
6
```

Apos o execucao, digite 'make clean' para apagar o arquivo do execucao e finalizar o passo.

Com a atividade, entendemos o uso do Mutex para os threads, que e bom para evitar fraudes.