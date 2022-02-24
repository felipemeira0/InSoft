# Atividade 1 - Processo Zumbi

Esse README apresenta um codigo que criam filhos de processo de um pai onde viram zumbis (que ja executam e nao encerra um processo).

### Comecando

1. O codigo "zombie.c" usa o funcao fork() onde criam filhos de processo de um pai, que depois o filho virou zumbi ate dar o comando "kill" para encerrar o processo. Para executar o codigo, usa-se o comando do Makefile "make run" junto com o "&" e "echo 'Z'" onde sao dois comandos para executar em um unico, para que pode o filho processor vira zumbi.
```
'$make run & echo "Z"'
```
2. E dai, o codigo esta sendo executando apos o "echo", criando um novo filho processor de um pai, e vamos verificar se o filho esta sendo 'zumbi'.
```
'$ps -l'
```
3. O terminal imprima a lista de processos onde o filho de um pai do codigo esta no 'Z' na coluna 'S' que e um zumbi, onde eu encontrei. Veja a lista de processos a partir de 'ps -l'.
```
	F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
	0 S  1003   12166   12158  0  80   0 -  4912 do_wai pts/0    00:00:00 bash
	0 S  1003   12524   12166  0  80   0 -  4271 do_wai pts/0    00:00:00 make
	0 S  1003   12525   12524  0  80   0 -   591 hrtime pts/0    00:00:00 bin
	1 Z  1003   12526   12525  0  80   0 -     0 -      pts/0    00:00:00 
	0 R  1003   12527   12166  0  80   0 -  5013 -      pts/0    00:00:00 ps
```
4. Logo, antes do 10 segundos do filho que esta no zumbi, usamos o comando 'kill' onde o PID do pai do filho vai encerrar o processo zumbi. O exemplo e que usamos apos a lista de processos exibido no terminal.
```
'$kill -9 12525'
```
imprima apos o comando 'kill'
```
'make: *** [Makefile:10: run] Killed'
```
5. Apos usar o comando 'kill', o zumbi e encerrado do processo e o terminal nao possui processos que esta no zumbi, veja a lista de processos a partir do comando 'ps -l', onde nao possui zumbis.
```
	F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
	0 S  1003   12166   12158  0  80   0 -  4912 do_wai pts/0    00:00:00 bash
	0 R  1003   12528   12166  0  80   0 -  5013 -      pts/0    00:00:00 ps
```
6. E dai, sem processo zumbi, e agora finalizamos o passo sobre o criacao de filho e encerramento de processos zumbis. Isso entendamos sobre o processo zumbi.

