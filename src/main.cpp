#include <iostream>
#include <fstream>
#include <ctime>
#include <system.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

static System sys;

string splitting(string line, bool isthefirst){
    size_t space = line.find(" ");
    if(isthefirst == true){
        string firstpart;
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
        string secondpart = line.substr(space + 1);
        return secondpart;
    }
}

bool onlySpaces(string name){
    bool onlysp = true;
    for(int i=0; i<name.length(); i++){
        if(name[i] != ' '){
            onlysp = false;
        }
    }
    return onlysp;
}

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

bool login(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para fazer login." << endl;
        return false;
    }else{
        string email = splitting(parameter, true);
        string password = splitting(parameter, false);
        bool tf = sys.loggingIn(email, password);
        return tf;
    }
}

bool creatingServer(string name){
    bool tf;
    if(name.length() == 0){
        cout << "Não há parâmetros suficientes para criar um servidor." << endl;
        return false;
    }
    bool istherespace = false;
    for(int i=0; i<name.size(); i++){
        if(name[i] == ' '){
            istherespace = true;
        }
    }
    if(istherespace == false){
        tf = sys.addServerToSystem(name, true);
        return tf;
    }else{
        cout << "Nome do servidor não pode ter espaço." << endl;
        return false;
    }
}

void settingServerDescription(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para definir a descrição do servidor." << endl;
        return;
    }else{
        string name = splitting(parameter, true);
        string description = splitting(parameter, false);
        sys.setServerDescription(name, description, true);
        return;
    }
}

void settingServerInviteCode(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para definir o código de convite do servidor." << endl;
        return;
    }else{
        string name = splitting(parameter, true);
        string ic = splitting(parameter, false);
        sys.setServerInviteCode(name, ic, true);
        return;
    }
}

void removingServer(string parameter){
    if(parameter.length() == 0){
        cout << "Não há parâmetros suficientes para remover o servidor." << endl;
    }else{
        sys.removeServer(parameter);
    }
}

bool enteringServer(string parameter){
    bool tf;
    string name = splitting(parameter, true);
    string ic = splitting(parameter, false);
    tf = sys.enteringServer(name, ic, true);
    return tf;
}

void creatingChannel(string parameter){
    if (parameter.length() == 0) {
        cout << "Não há parâmetros suficientes para criar o canal." << endl;
        return;
    }
    /*int spaces = 0;
    for (int i = 0; i < parameter.length(); i++) {
        if (parameter[i] == ' ') {
            spaces++;
        }
    }
    if(spaces == 0){
        cout << "Não há parâmetros suficientes para criar o canal." << endl;
        return;
    }*/
    string name, type;
    name = splitting(parameter, true);
    type = splitting(parameter, false);
    if(type != "texto" && type != "voz"){
        cout << "Tipo inválido!" << endl;
        return;
    }else if(type == "texto"){
        sys.newChannel(name, true, true);
    }else if(type == "voz"){
        sys.newChannel(name, false, true);
    }
}

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
    string choice, parameter, temp; bool tf; int i = 0, logstage = 0;
    do{
        sys.load();
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
                        tf = enteringServer(parameter);
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
                        char datetime[80]; struct tm *p;
                        time_t seconds; time(&seconds);
                        p = localtime(&seconds); strftime(datetime, 80, "<%d/%m/%Y - %X>", p);
                        if(parameter != ""){
                            sys.sendingMessage(datetime, parameter);
                        }
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
        sys.save();
    }while(choice != "quit");
    sys.ChannelsDestroyer();
    cout << "「「「 Saindo do Concordo... Até mais! 」」」" << endl;
    return 0;
}