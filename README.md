# Concordo
### Clone do Discord, para humanos mais civilizados.
O Concordo é um sistema com recursos similares ao Discord, porém funciona somente em modo texto e sem recursos de rede.

## Executando o Concordo
Instale o g++ e o cmake em seu computador.

Para compilar o programa, execute os comandos `cmake <diretório-do-programa>` e `make`.

Para executar o programa, após compilado:
1. **Caso não possua um script**: `./program`
2. **Caso possua um script**: `./program script.txt`

## Guia de Uso
### Comandos que estão sempre disponíveis:
>1. **quit**: Sai do Concordo.
>2. **list-servers**: Exibe a lista de servidores atualmente no sistema.
### Disponível caso o usuário não esteja logado:<br>
>3. **create-user**: O comando `create-user <email> <senha-sem-espaços> <nome-com-espaços>` tem a finalidade de criar um novo usuário no sistema.<br>
>4. **login**: O comando `login <email> <senha>` possibilita que o usuário efetue login no sistema.<br>
>5. **disconnect**: Desconecta o usuário atualmente logado no sistema.<br>
### Disponível caso o usuário esteja logado:
>6. **create-server**: O comando `create-server <nome-do-servidor>` serve para que o usuário, após logado no sistema, crie um servidor no sistema. Após criado o servidor, o usuário que o criou passa a fazer parte do servidor automaticamente.<br>
>7. **set-server-desc**: O comando `set-server-desc <nome-do-servidor> <descrição>` permite que o usuário, dono do servidor, defina a descrição do servidor.<br>
>8. **set-server-invite-code**: O comando `set-server-invite-code <nome-do-servidor> <código-de-convite>` possibilita que o usuário, dono do servidor, defina o código de convite do servidor.<br>
>9. **remove-server**: O comando `remove-server <nome-do-servidor>` permite que o usuário, dono do servidor, remova o servidor do sistema.<br>
>10. **enter-server**: O comando `enter-server <nome-do-servidor> <código-de-convite>` permite que o usuário entre em um servidor. Importante mencionar que o código de convite não é necessário quando o usuário é dono do servidor ou o servidor não possui código de convite.<br>
### Disponível caso o usuário, uma vez logado, esteja visualizando um servidor:<br>
>11. **leave-server**: O comando `leave-server` permite que o usuário se desconecte do servidor que está atualmente logado. O comando não remove o usuário da lista de participantes do servidor.<br>
>12. **list-participants**: Exibe o nome de todos os usuários que estão no servidor que o usuário está atualmente conectado.<br>
>13. **list-channels**: Exibe a lista de canais presentes no servidor que o usuário está atualmente conectado.<br>
>14. **create-channel**: O comando `create-channel <nome-do-canal> <tipo-do-canal>` permite que o usuário, uma vez conectando a um servidor, crie um canal de texto ou de voz.<br>
>15. **enter-channel**: O comando `enter-channel <nome-do-canal>` permite que o usuário, uma vez conectando a um servidor, entre em um canal de texto ou de voz, caso esse canal exista.<br>
### Disponível caso o usuário, uma vez logado, esteja visualizando um canal:<br>
>16. **leave-channel**: O usuário sai do canal o qual está conectado quando este comando é executado.<br>
>17. **send-message**: O comando `send-message <mensagem>` permite que o usuário, uma vez em um canal de texto ou de voz, envie uma mensagem para o referido canal.<br>
>18. **list-messages**: Caso o usuário esteja em um canal de texto, o comando `list-messages` mostra o histórico de todas as mensagens que foram enviadas ao canal. Caso o usuário esteja em um canal de voz, o comando `list-messages` mostra a última mensagem enviada ao canal.<br>

## Limitações
Durante as execuções, afim de testar o programa, não foi encontrada nenhuma limitação que prejudique o bom funcionamento do mesmo.

Ao criar um servidor, o usuário não pode escolher um nome para o servidor que tenha espaço, pois isso poderia causar conflito nos seguintes comandos: `set-server-desc <nome-do-servidor> <descrição>` e `set-server-invite-code <nome-do-servidor> <código-de-convite>`. Porém, isso não prejudica o bom funcionamento do programa, pois o mesmo avisa ao usuário que ele não pode fazer isso e o oferece a oportunidade de tentar criar um servidor novamente com outro nome.

---

Desenvolvido por Renzo Zukeram