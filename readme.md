# Concordo

## Identificação
Aluno: Renzo Paulo da Silva Zukeram

Matrícula: 20220041269

Turma: 01

## Sobre o programa
O Concordo é um sistema com recursos similares ao Discord, porém funciona somente em modo texto e sem recursos de rede.

## Executando o programa
Instale o g++ e o cmake em seu computador.

Para compilar o programa, execute o comando "cmake <diretório-do-programa>" e "make" em seguida.

Para executar o programa, após compilado:
1. **caso não possua um script**: "./program"
2. **caso possua um script**: "./program script.txt"

## Guia de Uso
1. **quit**: Sai do sistema.
2. **create-user**: O comando "create-user <email> <senha-sem-espaços> <nome-com-espaços>" tem a finalidade de criar um novo usuário no sistema.
3. **login**: O comando "login <email> <senha>" possibilita que o usuário efetue login no sistema.
4. **disconnect**: Desconecta o usuário atualmente logado no sistema.
5. **create-server**: O comando "create-server <nome-do-servidor> serve para que o usuário, após logado no sistema, crie um servidor no sistema. Após criado o servidor, o usuário que o criou passa a fazer parte do servidor automaticamente.
6. **set-server-desc**: O comando "set-server-desc <nome-do-servidor> <descrição>" permite que o usuário, dono do servidor, defina a descrição do servidor.
7. **set-server-invite-code**: O comando "set-server-invite-code <nome-do-servidor> <código-de-convite>" possibilita que o usuário, dono do servidor, defina o código de convite do servidor.
8. **list-servers**: Exibe a lista de servidores atualmente no servidor.
9. **remove-server**: O comando "remove-server <nome-do-servidor>" permite que o usuário, dono do servidor, remova o servidor do sistema.
10. **enter-server**: O comando "enter-server <nome-do-servidor> <código-de-convite>" permite que o usuário entre em um servidor. Importante mencionar que o código de convite não é necessário quando o usuário é dono do servidor ou o servidor não possui código de convite.
11. **leave-server**: O comando "leave-server" permite que o usuário se desconecte do servidor que está atualmente logado. O comando não remove o usuário da lista de participantes do servidor.
12. **list-participants**: Exibe o nome de todos os usuários que estão no servidor que o usuário está atualmente conectado.
13. **list-channels**: Exibe a lista de canais presentes no servidor que o usuário está atualmente conectado.
14. **create-channel**: O comando "create-channel <nome-do-canal> <tipo-do-canal>" permite que o usuário, uma vez conectando a um servidor, crie um canal de texto ou de voz.
15. **enter-channel**: O comando "enter-channel <nome-do-canal>" permite que o usuário, uma vez conectando a um servidor, entre em um canal de texto ou de voz, caso esse canal exista.
16. **leave-channel**: O usuário sai do canal o qual está conectado quando este comando é executado.
17. **send-message**: O comando "send-message <mensagem>" permite que o usuário, uma vez em um canal de texto ou de voz, envie uma mensagem para o referido canal.
18. **list-messages**: Caso o usuário esteja em um canal de texto, o comando "list-messages" mostra o histórico de todas as mensagens que foram enviadas ao canal. Caso o usuário esteja em um canal de voz, o comando "list-messages" mostra a última mensagem enviada ao canal.

## Limitações
Durante as execuções, afim de testar o programa, não foi encontrada nenhuma limitação que prejudique o bom funcionamento do mesmo.

Ao criar um servidor, o usuário não pode escolher um nome para o servidor que tenha espaço, pois isso poderia causar conflito nos seguintes comandos "set-server-desc <nome-do-servidor> <descrição>" e "set-server-invite-code <nome-do-servidor> <código-de-convite>". Porém, isso não prejudica o bom funcionamento do programa, pois o mesmo avisa ao usuário que ele não pode fazer isso e o oferece a oportunidade de tentar criar um servidor novamente com outro nome.

Há alguns vazamentos de memória no programa. A minha principal suspeita é que ela está relacionada à classe Message e/ou às classes Channel, TextChannel e VoiceChannel. O vazamento somente ocorre quando mensagens são enviadas pelos usuários.

## Dificuldades
Minha principal dificuldade neste projeto até agora foi trabalhar com polimorfismo, pois é algo que eu nunca havia trabalhado antes. Apesar da dificuldade, a experiência foi boa, pois deu para aprender bastante.

Também tive dificuldade para lidar com vazamentos de memórias que ocorreram durante a parte 2. Quando eu estava criando as classes Channel, TextChannel e VoiceChannel, houve alguns vazamentos de memória que eu consegui solucionar. Porém, ao criar a classe Message e seus respectivos métodos em TextChannel e VoiceChannel, vazamentos voltaram a acontecer e eu, infelizmente, não consegui identificar a raiz de problema e solucioná-los. Eu tentarei solucionar os vazamentos de memória que ainda restam até a entrega da parte 3.