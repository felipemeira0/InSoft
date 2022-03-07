# Atividade 2 - Pipe

Neste atividade, usamos um novo funcao do C 'Pipe' no qual cria um pai com variavel de tipo int ou char, e quando o pai le o variavel a partir de um pipe, retorna a variavel e o pipe despenca.

Neste codigo, vamos criar um array de mensagem do tipo char que usamos para o pipe, e primeiro e entrar um pipe com a palavra ou numero ate que algum pai leia a palavra ou numero de um pipe. Quando o pai le a palavra ou numero a partir de um pipe, a palavra ou numero do pipe despenca, ou entao, e vazio.

### Passo

Primeiro, dar o Makefile, usando 'make bin' e depois 'make run' para executar o codigo para testar o que o 'pipe' esta funcionando.

Depois de executar o comando 'make run', o terminal exiba:

```
Write message from pipe 0, result Hello world!
Read message from pipe 0, result Hello world!
Write message from pipe 1, result from Pipe!
Read message from pipe 1, result from Pipe!
```

Isso entendemos sobre o novo funcao chamado Pipe.

