/**
 * @file main.cpp
 * @author Renzo Zukeram
 * @brief Implementação da leitura do script e dos comandos a serem executados pelo usuário.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <fstream>
#include <ctime>
#include <system.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

static System sys;

/**
 * @brief Divide uma string em duas partes no primeiro espaço encontrado.
 *
 * @param line A string de entrada a ser dividida.
 * @param isthefirst Flag indicando se deve retornar a primeira parte (verdadeiro) ou a segunda parte (falso).
 * @return A primeira ou segunda parte da string dividida.
 */
string splitting(string line, bool isthefirst){
    size_t space = line.find(" "); string firstpart, secondpart;
    if(isthefirst == true){
        firstpart = line.substr(0, space);
        return firstpart;
    }else{
        int spaces = 0;
        for(int i=0; i<line.length(); i++){
            if(line[i] == ' '){
                spaces++;
            }
        }
        if(spaces == 0){
            return "";
        }
        secondpart = line.substr(space + 1);
        return secondpart;
    }
}

/**
 * @brief Verifica se uma string contém apenas espaços.
 *
 * @param name A string de entrada a ser verificada.
 * @return Verdadeiro se a string contém apenas espaços, falso caso contrário.
 */
bool onlySpaces(string name){
    bool onlysp = true;
    for(int i=0; i<name.length(); i++){
        if(name[i] != ' '){
            onlysp = false;
        }
    }
    return onlysp;
}

/**
 * @brief Trata o comando de cadastro de usuário.
 *
 * @param parameter A string de parâmetro contendo e-mail, senha e nome.
 */
void signup(string parameter){
    int spaces = 0; string email, password, name; 
    for(int i=0; i<parameter.length(); i++){
        if(parameter[i] == ' '){
            spaces++;
        }
    }
    if(spaces < 2){
        cout << "Não há parâmetros suficientes para criar um novo usuário." << endl;
    }else{
        spaces = 0;
        for(int i=0; i<parameter.length(); i++){
            if(parameter[i] == ' ' && spaces < 2){
                spaces++;
            }else{
                if(spaces == 0){
                    email += parameter[i];
                }else if(spaces == 1){
                    password += parameter[i];
                }else if(spaces == 2){
                    name += parameter[i];
                }
            }
        }
        if(email.length() > 0 && password.length() > 0 && name.length() > 0){
            bool tf = onlySpaces(name);
            if(tf == true){
                name = "sem-nome";
            }
            sys.addUserToSystem(email, password, name);
        }else{
            if(email.length() == 0){
                cout << "O e-mail deve ter pelo menos 1 caractere." << endl;
            }
            if(password.length() == 0){
                cout << "A senha deve ter pelo menos 1 caractere." << endl;
            }
            if(name.length() == 0){
                cout << "O nome deve ter pelo menos 1 caractere." << endl;
            }
        }
    }
}

/**
 * @brief Trata o comando de login.
 *
 * @param parameter A string de parâmetro contendo e-mail e senha.
 * @return Verdadeiro se o login for bem-sucedido, falso caso contrário.
 */
bool login(string parameter){
    int spaces = 0; string email, password; bool tf;
    for(int i=0; i<parameter.length(); i++){
        if(parameter[i] == ' '){
            spaces++;
        }
    }
    if(spaces < 1){
        cout << "Não há parâmetros suficientes para fazer login." << endl;
        return false;
    }else{
        spaces = 0;
        for(int i=0; i<parameter.length(); i++){
            if(parameter[i] == ' ' && spaces < 1){
                spaces++;
            }else{
                if(spaces == 0){
                    email += parameter[i];
                }else if(spaces == 1){
                    password += parameter[i];
                }
            }
        }
        tf = sys.loggingIn(email, password);
    }
    return tf;
}

/**
 * @brief Trata o comando de criação de servidor.
 *
 * @param name O nome do servidor a ser criado.
 */
bool creatingServer(string name){
    bool tf;
    if(name.length() == 0){
        cout << "Não há parâmetros suficientes para criar um servidor." << endl;
        return false;
    }
    bool istherespace = true;
    for(int i=0; i<name.size(); i++){
        if(name[i] == ' '){
            istherespace = false;
        }
    }
    if(istherespace == true){
        tf = sys.addServerToSystem(name);
        return tf;
    }else{
        cout << "Nome do servidor não pode ter espaço." << endl;
        return false;
    }
}

/**
 * @brief Trata o comando de definição de descrição do servidor.
 *
 * @param parameter A string de parâmetro contendo o nome do servidor e a descrição.
 */
void settingServerDescription(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para definir a descrição do servidor." << endl;
        return;
    }
    int spaces = 0; string name, description;
    for(int i=0; i<parameter.length(); i++){
        if(parameter[i] == ' '){
            spaces++;
        }
    }
    if(spaces < 1){
        description = ""; name = parameter;
    }else{
        spaces = 0;
        for(int i=0; i<parameter.length(); i++){
            if(parameter[i] == ' ' && spaces < 1){
                spaces++;
            }else{
                if(spaces == 0){
                    name += parameter[i];
                }else if(spaces == 1){
                    description += parameter[i];
                }
            }
        }
    }
    sys.setServerDescription(name, description);
}

/**
 * @brief Trata o comando de definição do código de convite do servidor.
 *
 * @param parameter A string de parâmetro contendo o nome do servidor e o código de convite.
 */
void settingServerInviteCode(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para definir o código de convite do servidor." << endl;
        return;
    }
    int spaces = 0; string name, ic;
    for(int i=0; i<parameter.length(); i++){
        if(parameter[i] == ' '){
            spaces++;
        }
    }
    if(spaces < 1){
        ic = ""; name = parameter;
    }else{
        spaces = 0;
        for(int i=0; i<parameter.length(); i++){
            if(parameter[i] == ' ' && spaces < 1){
                spaces++;
            }else{
                if(spaces == 0){
                    name += parameter[i];
                }else if(spaces == 1){
                    ic += parameter[i];
                }
            }
        }
    }
    sys.setServerInviteCode(name, ic);
}

/**
 * @brief Trata o comando de remoção de servidor.
 *
 * @param parameter O nome do servidor a ser removido.
 */
void removingServer(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para remover o servidor." << endl;
    }else{
        sys.removeServer(parameter);
    }
}

/**
 * @brief Cria um canal com base nos parâmetros fornecidos.
 *
 * Esta função cria um canal com base nos parâmetros fornecidos, que incluem o nome do canal e o tipo do canal.
 * O tipo do canal pode ser "texto" ou "voz".
 *
 * @param parameter Uma string contendo os parâmetros necessários para criar o canal.
 */
void creatingChannel(string parameter){
    if (parameter.length() == 0) {
        cout << "Não há parâmetros suficientes para criar o canal." << endl;
        return;
    }
    int spaces = 0;

    for (int i = 0; i < parameter.length(); i++) {
        if (parameter[i] == ' ') {
            spaces++;
        }
    }
    if(spaces == 0){
        cout << "Não há parâmetros suficientes para criar o canal." << endl;
        return;
    }
    string name, type;
    name = splitting(parameter, true);
    type = splitting(parameter, false);
    if(type != "texto" && type != "voz"){
        cout << "Tipo inválido!" << endl;
        return;
    }else if(type == "texto"){
        sys.newChannel(name, true);
    }else if(type == "voz"){
        sys.newChannel(name, false);
    }
}

/**
 * @brief Entra em um canal existente.
 *
 * Esta função permite que o usuário entre em um canal existente com base no parâmetro fornecido.
 *
 * @param parameter Uma string contendo o parâmetro necessário para entrar no canal.
 * @return Um valor booleano indicando se a entrada no canal foi bem-sucedida ou não.
 */
bool enteringChannel(string parameter, bool changing){
    bool tf;
    if(parameter == ""){
        cout << "Não há parâmetros suficientes para entrar em um canal." << endl;
        return false;
    }else{
        tf = sys.enteringChannel(parameter, changing);
    }
    return tf;
}

/**
 * @brief Lê e processa os comandos do usuário.
 *
 * @param commands O vetor contendo os comandos do script fornecido pelo usuário.
 * @param choice O comando recebido do arquivo ou digitado pelo usuário.
 * @param parameter Reune os parâmetros do comando digitado pelo usuário.
 * @param tf Um boolean auxiliar para algumas situações específicas.
 * @param logstage Verifica em qual nível de acesso o usuário está. Por exemplo: Quando logstage = 0: usuário não logado; Quando logstage = 1: usuário logado; Quando logstage = 2: usuário logado e visualizando um servidor; Quando logstage = 3: usuário logado, visualizando um servidor e visualizando um canal.
 * 
 */
void readingCommands(vector<string> commands){
    string choice, parameter, temp; bool tf; int i = 0, logstage;
    do{
        if(i < commands.size()){
            choice = splitting(commands[i], true);
            parameter = splitting(commands[i], false);
            i++;
        }else if(i == commands.size()){
            getline(cin, temp);
            choice = splitting(temp, true);
            parameter = splitting(temp, false);
        }
        if(choice != "quit"  && choice != "create-user" && choice != "login" && choice != "disconnect" && choice != "create-server" && choice != "set-server-desc" && choice != "set-server-invite-code" && choice != "list-servers" && choice != "remove-server" && choice != "enter-server" && choice != "leave-server" && choice != "list-participants" && choice != "list-channels" && choice != "create-channel" && choice != "enter-channel" && choice != "leave-channel" && choice != "send-message" && choice != "list-messages"){
            cout << "Comando inválido!" << endl;
        }else{
            if(choice == "list-servers"){
                sys.listServers();
            }
            if(logstage > 3 || logstage < 0){
                logstage = 0;
            }
            if(logstage == 0){
                if(choice == "create-user"){
                    signup(parameter);
                }else if(choice == "login"){
                    tf = login(parameter);
                    if(tf == true){
                        logstage = 1;
                    }
                }else if(choice == "disconnect"){
                    cout << "Você não está logado no sistema." << endl;
                }else if(choice == "create-server" || choice == "set-server-desc" || choice == "set-server-invite-code" || choice == "remove-server" || choice == "enter-server" || choice == "leave-server" || choice == "list-participants" || choice == "list-channels" || choice == "create-channel" || choice == "enter-channel" || choice == "leave-channel" || choice == "send-message" || choice == "list-messages"){
                    cout << "Você deve estar logado para poder executar isso." << endl;
                }
            }else{
                if(choice == "create-user" || choice == "login"){
                    cout << "Você já está logado." << endl;
                }else if(choice == "disconnect"){
                    logstage = 0; sys.disconnect();
                }else if(choice == "create-server"){
                    if(logstage == 1){
                        tf = creatingServer(parameter);
                        if(tf == true){
                            logstage = 2;
                        }
                    }else if(logstage == 2 || logstage == 3){
                        cout << "Você já está conectado a um servidor." << endl;
                    }
                }else if(choice == "set-server-desc"){
                    settingServerDescription(parameter);
                }else if(choice == "set-server-invite-code"){
                    settingServerInviteCode(parameter);
                }else if(choice == "remove-server"){
                    removingServer(parameter);
                }else if(choice == "enter-server"){
                    if(logstage == 1){
                        tf = sys.enteringServer(parameter);
                        if(tf == true){
                            logstage = 2;
                        }
                    }else if(logstage == 2 || logstage == 3){
                        cout << "Você já está conectado a um servidor." << endl;
                    }
                }else if(choice == "leave-server"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2 || logstage == 3){
                        sys.leavingServer(true);
                        logstage = 1;
                    }
                }else if(choice == "list-participants"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2 || logstage == 3){
                        sys.listParticipants();
                    }
                }else if(choice == "list-channels"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2 || logstage == 3){
                        sys.printChannels();
                    }
                }else if(choice == "create-channel"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2 || logstage == 3){
                        creatingChannel(parameter);
                    }
                }else if(choice == "enter-channel"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2 || logstage == 3){
                        tf = enteringChannel(parameter, logstage - 2);
                        if(tf == true){
                            logstage = 3;
                        }
                    }
                }else if(choice == "leave-channel"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2){
                        cout << "Você deve estar em um canal para poder executar isso." << endl;
                    }else if(logstage == 3){
                        sys.leavingChannel();
                        logstage = 2;
                    }
                }else if(choice == "send-message"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2){
                        cout << "Você deve estar em um canal para poder executar isso." << endl;
                    }else if(logstage == 3){
                        char date[80]; struct tm *p;
                        time_t seconds; time(&seconds);
                        p = localtime(&seconds); strftime(date, 80, "<%d/%m/%Y - %X>", p);
                        sys.sendingMessage(date, parameter);
                    }
                }else if(choice == "list-messages"){
                    if(logstage == 1){
                        cout << "Você deve estar em um servidor para poder executar isso." << endl;
                    }else if(logstage == 2){
                        cout << "Você deve estar em um canal para poder executar isso." << endl;
                    }else if(logstage == 3){
                        sys.printMessages();
                    }
                }
            }
        }
    }while(choice != "quit");
    sys.ChannelsDestroyer();
}

/**
 * @brief Função principal do aplicativo Concordo.
 *
 * @param argc O número de argumentos a serem recebidos.
 * @param argv Um array composto pelos argumentos recebidos.
 * @return O status de saída do aplicativo.
 */
int main(int argc, char* argv[]){
    system("clear");
    cout << "「「「 Bem-vindo ao concordo! 」」」" << endl;
    vector<string> commands;
    if(argc >= 2){
        string temp;
        ifstream file(argv[1]);
        while(getline(file, temp)){
            commands.push_back(temp);
        }
        file.close();
    }
    readingCommands(commands);
    cout << "「「「 Saindo do Concordo... Até mais! 」」」" << endl;

    return 0;
}