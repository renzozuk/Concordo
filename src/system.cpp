#include <iostream>
#include <fstream>
#include <cmath>
#include <system.h>

using std::cin;
using std::cout;
using std::endl;
using std::pow;
using std::ifstream;
using std::ofstream;

void System::ChannelsDestroyer(){
    for(int i = 0; i < servers.size(); i++){
        servers[i].ChannelsDestroyer();
    }
}

int System::getIntByString(string befn){
    int aftn = 0;
    for (int i = 0; i < befn.length(); i++) {
        aftn += (befn[befn.length()-1-i]-'0') * pow(10, i);
    }
    return aftn;
}

//start users
void System::setLoggedInUser(User currentLoggedInUser){
    this->currentLoggedInUser = currentLoggedInUser;
}

/*User System::getLoggedInUser(){
    return this->currentLoggedInUser;
}*/

void System::setLoggedInUserById(int id){
    for(int i = 0; i < users.size(); i++){
        if(users[i].getId() == id){
            this->currentLoggedInUser = users[i];
        }
    }
}

string System::getUserNameById(int id){
    string name;
    for(int i=0; i<users.size(); i++){
        if(users[i].getId() == id){
            name = users[i].getName();
        }
    }
    return name;
}

bool System::alExistUser(string newemail){
    bool isequal = false;
    for(int i=0; i<users.size(); i++){
        if(newemail == users[i].getEmail()){
            isequal = true;
            break;
        }
    }
    return isequal;
}

void System::addUserToSystem(const string& email, const string& password, const string& name){
    if(System::alExistUser(email) == true){
        cout << "Usuário já existe!" << endl;
    }else{
        int size_ = users.size() + 1;
        User usr(size_, email, password, name);
        users.push_back(usr);
        cout << "Criando usuário: " << name << " (" << email << ")" << endl << "Usuário criado." << endl;
    }   
}

bool System::loggingIn(string email, string password){
    for(int i=0; i<users.size(); i++){
        if(email == users[i].getEmail() && password == users[i].getPassword()){
            cout << "Usuário logado como " << email << endl;
            System::setLoggedInUser(users[i]);
            return true;
        }else if(email == users[i].getEmail() && password != users[i].getPassword()){
            cout << "Senha incorreta." << endl;
            return false;
        }
    }
    cout << "Não há nenhum usuário no sistema que corresponde com os dados inseridos. Verifique os dados inseridos e tente novamente." << endl;
    return false;
}

void System::disconnect(){
    for(int i=0; i<users.size(); i++){
        if(users[i].getId() == currentLoggedInUser.getId()){
            cout << "Desconectando usuário... " << endl;
        }
    }
    System::setLoggedInUser(User()); System::setCurrentServer(Server()); System::setCurrentChannel(Channel());
}
//end users

//start servers
void System::setCurrentServer(Server currentServer){
    this->currentServer = currentServer;
}

bool System::alExistServer(string newname){
    bool isequal = false;
    for(int i=0; i<servers.size(); i++){
        if(newname == servers[i].getName()){
            isequal = true;
            break;
        }
    }
    return isequal;
}

bool System::addServerToSystem(string name, bool toPrint){
    bool alexist = System::alExistServer(name);
    if(alexist == false){
        Server srv(currentLoggedInUser.getId(), name);
        servers.push_back(srv);
        if(toPrint == true){
            cout << "Servidor criado." << endl;
        }
        System::enteringServer(name, "", false);
        return true;
    }else{
        if(toPrint == true){
            cout << "Servidor com esse nome já existe." << endl;
        }
        return false;
    }
}

void System::setServerDescription(string name, string desc, bool toPrint){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers[i].setDescription(desc);
                if(toPrint == true){
                    cout << "Descrição do servidor '" << name;
                    if(desc != ""){
                        cout << "' modificada!" << endl;
                    }else{
                        cout << "' removida!" << endl;
                    }
                }
            }else{
                if(toPrint == true){
                    cout << "Você não pode alterar a descrição de um servidor que não foi criado por você." << endl;
                }
            }
        }
    }
    if(found == false){
        cout << "Servidor '" << name << "' não existe." << endl;
    }
}

void System::setServerInviteCode(string name, string ic, bool toPrint){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers[i].setInviteCode(ic);
                if(toPrint == true){
                    cout << "Código de convite do servidor '" << name;
                    if(ic.length() != 0){
                        cout << "' modificado!" << endl;
                    }else{
                        cout << "' removido!" << endl;
                    }
                }
            }else{
                if(toPrint == true){
                    cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você." << endl;
                }
            }
        }
    }
    if(found == false){
        cout << "Servidor '" << name << "'não existe." << endl;
    }
}

void System::listServers(){
    if(servers.size() == 0){
        cout << "Não há nenhum server no sistema." << endl;
    }else{
        cout << "「 Lista de servidores no sistema 」" << endl;
        for(int i=0; i<servers.size(); i++){
            cout << servers[i].getName() << endl;
        }
        cout << "「 Fim da lista 」" << endl;
    }
}

void System::removeServer(string name){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers.erase(servers.begin()+i);
                cout << "Servidor '" << name << "' removido." << endl;
            }else{
                cout << "Você não é dono do servidor '" << name << "'." << endl;
            }
        }
    }
    if(found == false){
        cout << "Servidor '" << name << "' não encontrado." << endl;
    }
}

bool System::enteringServer(string name, string ic, bool toPrint){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(ic == servers[i].getInviteCode() || currentLoggedInUser.getId() == servers[i].getOwnerId() || servers[i].getInviteCode() == ""){
                servers[i].enteringServer(currentLoggedInUser.getId());
                System::setCurrentServer(servers[i]);
                if(toPrint == true){
                    cout << "Entrou no servidor '"<< servers[i].getName() <<"' com sucesso." << endl;
                }
                return true;
            }else if(ic == "" && servers[i].getInviteCode() != ""){
                if(toPrint == true){
                    cout << "Servidor requer código de convite." << endl;
                }
            }else if(servers[i].getInviteCode() != "" && ic != "" && ic != ""){
                if(toPrint == true){
                    cout << "Código de convite incorreto. Verifique se os dados inseridos estão corretos e tente novamente." << endl;
                }
            }
        }
    }
    if(found == false){
        cout << "Servidor não encontrado." << endl;
    }
    return false;
}

void System::leavingServer(bool toprint){
    cout << "Saindo do servidor '" << currentServer.getName() << "'." << endl;
    System::setCurrentServer(Server()); System::setCurrentChannel(Channel());
}

void System::listParticipants(){
    int* membersid;
    for(int i=0; i<servers.size(); i++){
        if(servers[i].getName() == currentServer.getName()){
            membersid = servers[i].getListMembers();
            cout << "「 Lista de membros do servidor '" << servers[i].getName() << "' 」" << endl;
            for(int j=0; j<System::servers[i].getQuantMembers(); j++){
                cout << System::getUserNameById(membersid[j]) << endl;
            }
            cout << "「 Fim da lista 」" << endl;
        }
    }
    delete[] membersid;
}
//end servers

//start channels
void System::setCurrentChannel(Channel currentChannel){
    this->currentChannel = currentChannel;
}

void System::newChannel(string name, bool isText, bool toPrint){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            servers[i].addChannelToServer(name, isText, toPrint);
        }
    }
}

void System::printChannels(){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            cout << "「 Lista de canais do servidor '" << servers[i].getName() << "' 」" << endl;
            servers[i].printChannels();
            cout << "「 Fim da lista 」" << endl;
        }
    }
}

bool System::enteringChannel(string name, bool changing){
    bool found;
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            found = servers[i].alExistChannel(name);
            if(found == true){
                if(changing == false){
                    currentChannel = servers[i].getChannel(name);
                    cout << "Entrando no canal '" << currentChannel.getName() << "'." << endl;
                }else{
                    string old = currentChannel.getName();
                    currentChannel = servers[i].getChannel(name);
                    string nova = currentChannel.getName();
                    if(old == nova){
                        cout << "Você já está no canal '" << currentChannel.getName() << "'." << endl;
                    }else{
                        cout << "Saindo do canal '" << old << "' e entrando no canal '" << nova << "'." << endl;
                    }
                }
            }else{
                cout << "Canal '" << name << "' não existe." << endl;
            }
        }
    }
    return found;
}

void System::leavingChannel(){
    cout << "Saindo do canal." << endl;
    System::setCurrentChannel(Channel());
}

void System::sendingMessage(string date, string content){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            int sentBy = currentLoggedInUser.getId();
            servers[i].sendingMessage(date , sentBy, content, currentChannel.getName());
        }
    }
}

void System::printMessages(){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            if(servers[i].getChannelType(currentChannel.getName()) == "text"){
                string sentBy, datetime, content; int atualid;
                if(servers[i].getQuantMessages(currentChannel.getName()) != 0 && servers[i].getSpecificMessageContent(currentChannel.getName(), 0) == ""){
                    cout << "Sem mensagens para exibir." << endl;
                    return;
                }
                for(int j=0; j<servers[i].getQuantMessages(currentChannel.getName()); j++){
                    atualid = servers[i].getSpecificMessageSentBy(currentChannel.getName(), j);
                    datetime = servers[i].getSpecificMessageDateTime(currentChannel.getName(), j);
                    content = servers[i].getSpecificMessageContent(currentChannel.getName(), j);
                    sentBy = getUserNameById(atualid);
                    cout << sentBy << datetime << ": " << content << endl;
                }
            }else if(servers[i].getChannelType(currentChannel.getName()) == "voice"){
                if(servers[i].getLastMessageContent(currentChannel.getName()) == ""){
                    cout << "Sem mensagens para exibir." << endl;
                    return;
                }
                cout << getUserNameById(servers[i].getLastMessageSentBy(currentChannel.getName())) << servers[i].getLastMessageDateTime(currentChannel.getName()) << ": " << servers[i].getLastMessageContent(currentChannel.getName()) << endl;
            }
        }
    }
}
//end channels

//start disk-data
void System::saveUsers(){
    ofstream UsersFile("usuarios.txt");
    UsersFile << users.size() << "\n";
    for(int i = 0; i < users.size(); i++){
        UsersFile << users[i].getId() << "\n";
        UsersFile << users[i].getName() << "\n";
        UsersFile << users[i].getEmail() << "\n";
        UsersFile << users[i].getPassword() << "\n";
    }
    UsersFile.close();
}

void System::saveServers(){
    ofstream ServersFile("servidores.txt");
    ServersFile << servers.size() << "\n";
    for(int i = 0; i < servers.size(); i++){
        ServersFile << servers[i].getOwnerId() << "\n";
        ServersFile << servers[i].getName() << "\n";
        ServersFile << servers[i].getDescription() << "\n";
        ServersFile << servers[i].getInviteCode() << "\n";
        ServersFile << servers[i].getQuantMembers() << "\n";
        for(int j = 0; j < servers[i].getQuantMembers(); j++){
            ServersFile << servers[i].getSpecificMemberIdByPosition(j) << "\n";
        }
        ServersFile << servers[i].getQuantChannels() << "\n";
        for(int j = 0; j < servers[i].getQuantChannels(); j++){
            ServersFile << servers[i].getChannelNameByPosition(j) << "\n";
            ServersFile << servers[i].getChannelType(servers[i].getChannelNameByPosition(j)) << "\n";
            if(servers[i].getChannelType(servers[i].getChannelNameByPosition(j)) == "text"){
                ServersFile << servers[i].getQuantMessages(servers[i].getChannelNameByPosition(j)) << "\n";
                for(int k = 0; k < servers[i].getQuantMessages(servers[i].getChannelNameByPosition(j)); k++){
                    ServersFile << servers[i].getSpecificMessageSentBy(servers[i].getChannelNameByPosition(j), k) << "\n";
                    ServersFile << servers[i].getSpecificMessageDateTime(servers[i].getChannelNameByPosition(j), k) << "\n";
                    ServersFile << servers[i].getSpecificMessageContent(servers[i].getChannelNameByPosition(j), k) << "\n";
                }
            }else if(servers[i].getChannelType(servers[i].getChannelNameByPosition(j)) == "voice"){
                if(servers[i].getLastMessageSentBy(servers[i].getChannelNameByPosition(j)) == 0){
                    ServersFile << 0 << "\n";
                }else{
                    ServersFile << 1 << "\n";
                    ServersFile << servers[i].getLastMessageSentBy(servers[i].getChannelNameByPosition(j)) << "\n";
                    ServersFile << servers[i].getLastMessageDateTime(servers[i].getChannelNameByPosition(j)) << "\n";
                    ServersFile << servers[i].getLastMessageContent(servers[i].getChannelNameByPosition(j)) << "\n";
                }
            }
        }
    }
}

void System::save(){
    System::saveUsers();
    System::saveServers();
}

void System::loadUsers(){
    ifstream UsersFile("usuarios.txt");
    if(UsersFile.good()){
        vector<string> lines; string temp;
        while(getline(UsersFile, temp)){
            lines.push_back(temp);
        }
        UsersFile.close();
        bool alexist;
        for(int i = 0; i < System::getIntByString(lines[0]); i++){
            alexist = System::alExistUser(lines[i*4+3]);
            if(alexist == false){
                User usr(System::getIntByString(lines[i*4+1]), lines[i*4+3], lines[4*(i+1)], lines[i*4+2]);
                users.push_back(usr);
            }
        }
    }
}

void System::loadServers(){
    ifstream ServersFile("servidores.txt");
    if(ServersFile.good()){
        servers.clear();
        vector<string> lines; string temp, temp1;
        while(getline(ServersFile, temp)){
            lines.push_back(temp);
        }
        ServersFile.close(); int i = 1;
        while(i < lines.size()){
            System::setLoggedInUserById(System::getIntByString(lines[i])); i++;
            System::addServerToSystem(lines[i], false);
            System::setServerDescription(lines[i], lines[i+1], false);
            System::setServerInviteCode(lines[i], lines[i+2], false);
            i += 3;
            for(int j = 0; j < System::getIntByString(lines[i]); j++){ //reading members
                System::setLoggedInUserById(System::getIntByString(lines[i+j+1]));
                System::enteringServer(lines[i-3], lines[i-1], false); temp = lines[i-3]; temp1 = lines[i-1];
            }
            i += (System::getIntByString(lines[i])+1);
            int quanttemp = System::getIntByString(lines[i]), quanttemp1; Channel tempch;
            if(System::getIntByString(lines[i]) == 0){
                i++;
            }
            for(int j = 0; j < quanttemp; j++){ //reading channels
                if(j == 0){
                    i++;
                }
                if(lines[i+1] == "text"){
                    System::newChannel(lines[i], true, false); temp1 = lines[i];
                    tempch = currentServer.getChannel(lines[i+1]); i += 2;
                    if(System::getIntByString(lines[i]) == 0){
                        i++;
                    }
                    quanttemp1 = System::getIntByString(lines[i]);
                    for(int k = 0; k < quanttemp1; k++){ //reading messages-tc
                        if(k == 0){
                            i++;
                        }
                        System::setLoggedInUserById(System::getIntByString(lines[i]));
                        for(int l = 0; l < servers.size(); l++){
                            System::setCurrentServer(servers[l]);
                            if(servers[l].getName() == temp){
                                this->currentChannel = servers[l].getChannel(temp1);
                            }
                        }
                        System::sendingMessage(lines[i+1], lines[i+2]);
                        i += 3;
                    }
                }else if(lines[i+1] == "voice"){
                    System::newChannel(lines[i], false, false); temp1 = lines[i];
                    tempch = currentServer.getChannel(lines[i+1]); i += 2;
                    if(System::getIntByString(lines[i]) == 0){
                        i++;
                    }else if(System::getIntByString(lines[i]) == 1){ //reading messages-vc
                        i++;
                        System::setLoggedInUserById(System::getIntByString(lines[i]));
                        for(int l = 0; l < servers.size(); l++){
                            System::setCurrentServer(servers[l]);
                            if(servers[l].getName() == temp){
                                this->currentChannel = servers[l].getChannel(temp1);
                            }
                        }
                        System::sendingMessage(lines[i+1], lines[i+2]);
                        i += 3;
                    }
                }
            }
        }
        System::setLoggedInUser(User()); System::setCurrentServer(Server()); System::setCurrentChannel(Channel());
    }
}

void System::load(){
    System::loadUsers();
    //System::loadServers();
}
//end disk-data