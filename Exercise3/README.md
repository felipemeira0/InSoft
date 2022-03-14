# Atividade 3 - Threads

Neste atividade, apresentamos de usar os threads de um computador, onde o thread permite criar funcoes do programa a partir de um codigo, e permite executar multiplos threads em um unico processor.

Neste codigo, vamos criar os tres threads, primeiro para calcular o valor minimo, segundo para calcular o valor maximo e terceiro para calcular o valor medio do array dos numeros. 

### Funcao do Codigo

main - O funcao onde executa o codigo.
findMinimumNumber - O funcao que e um thread para buscar e imprimir o numero que e minimo de um array.
findMaximumNumber - O funcao que e um thread para buscar e imprimir o numero que e maximo de um array.
findAverageNumber - O funcao que e um thread para calcular e imprimir o numero que e um valor medio de um array.

### Passo

Primeiro, dar o Makefile que possui tres funcoes, bin, run e clean. No terminal, com codigo, digite 'make bin' para compilar o programa, depois 'make run' para executar o codigo onde usa os tres threads e imprimir o resultado, depois 'make clean' para limpar o codigo binario.

### Resultado

Apos 'make run' a partir de 'make bin', a entrada e:
```
9 
70 86 72 58 64 80 74 86 68
```
e o resultado da saida e:
```
The minimum value is 58
The average value is 73
The maximum value is 86
```
NOTA: Essa linha da saida pode variar dependo do Mutex de thread (que melhora o runtime).
