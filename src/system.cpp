/**
 * @file system.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe System.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <system.h>

using std::cin;
using std::cout;
using std::endl;

void System::ChannelsDestroyer(){
    for(int i=0; i<servers.size(); i++){
        servers[i].ChannelsDestroyer();
    }
}

//start users
/**
 * @brief Obtém o usuário atualmente logado no sistema.
 *
 * @return O usuário atualmente logado.
 */
User System::getLoggedInUser(){
    return this->currentLoggedInUser;
}

/**
 * @brief Define o usuário atualmente logado no sistema.
 *
 * @param currentLoggedInUser O usuário atualmente logado.
 */
void System::setLoggedInUser(User currentLoggedInUser){
    this->currentLoggedInUser = currentLoggedInUser;
}

/**
 * @brief Obtém o nome de usuário correspondente a um determinado ID.
 *
 * @param id O ID do usuário.
 * @return O nome do usuário correspondente ao ID.
 */
string System::getUserNameById(int id){
    string name;
    for(int i=0; i<users.size(); i++){
        if(users[i].getId() == id){
            name = users[i].getName();
        }
    }
    return name;
}

/**
 * @brief Verifica se já existe um usuário com o mesmo e-mail no sistema.
 *
 * @param newemail O novo e-mail a ser verificado.
 * @return Verdadeiro se o e-mail já existir, falso caso contrário.
 */
bool System::alExistUser(string newemail){
    bool isequal = false; string emailinsys;
    for(int i=0; i<users.size(); i++){
        emailinsys = users[i].getEmail();
        if(newemail == emailinsys){
            isequal = true;
            break;
        }
    }
    return isequal;
}

/**
 * @brief Adiciona um usuário ao sistema.
 *
 * @param email O e-mail do usuário.
 * @param password A senha do usuário.
 * @param name O nome do usuário.
 */
void System::addUserToSystem(const string& email, const string& password, const string& name){
    bool alexist = System::alExistUser(email);
    if(alexist == true){
        cout << "Usuário já existe!" << endl;
    }else{
        int size_ = users.size() + 1;
        User usr(size_, email, password, name);
        users.push_back(usr);
        cout << "Criando usuário: " << name << " (" << email << ")" << endl << "Usuário criado." << endl;
    }   
}

/**
 * @brief Faz o login de um usuário no sistema.
 *
 * @param email O e-mail do usuário.
 * @param password A senha do usuário.
 * @return Verdadeiro se o login for bem-sucedido, falso caso contrário.
 */
bool System::loggingIn(string email, string password){
    string emailinsys, passwordinsys, name;
    for(int i=0; i<users.size(); i++){
        emailinsys = users[i].getEmail(); passwordinsys = users[i].getPassword();
        if(email == emailinsys && password == passwordinsys){
            cout << "Usuário logado como " << email << endl;
            System::setLoggedInUser(users[i]);
            return true;
        }else if(email == emailinsys && password != passwordinsys){
            cout << "Senha incorreta." << endl;
            return false;
        }
    }
    cout << "Não há nenhum usuário no sistema que corresponde com os dados inseridos. Verifique os dados inseridos e tente novamente." << endl;
    return false;
}

/**
 * @brief Desconecta o usuário atualmente logado no sistema.
 */
void System::disconnect(){
    for(int i=0; i<users.size(); i++){
        if(users[i].getId() == currentLoggedInUser.getId()){
            cout << "Desconectando usuário... " << endl;
        }
    }
    System::setLoggedInUser(User());
    System::setCurrentServer(Server());
    System::setCurrentChannel(Channel());
}
//end users

//start servers
/**
 * @brief Obtém o servidor atualmente selecionado.
 *
 * @return O servidor atualmente selecionado.
 */
Server System::getCurrentServer(){
    return this->currentServer;
}

/**
 * @brief Define o servidor atualmente selecionado.
 *
 * @param currentServer O servidor atualmente selecionado.
 */
void System::setCurrentServer(Server currentServer){
    this->currentServer = currentServer;
}

/**
 * @brief Verifica se já existe um servidor com o mesmo nome no sistema.
 *
 * @param newname O novo nome do servidor.
 * @return Verdadeiro se o servidor já existir, falso caso contrário.
 */
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

/**
 * @brief Adiciona um servidor ao sistema.
 *
 * @param name O nome do servidor.
 */
bool System::addServerToSystem(string name){
    bool alexist = System::alExistServer(name);
    if(alexist == false){
        Server srv(currentLoggedInUser.getId(), name);
        servers.push_back(srv);
        cout << "Servidor criado." << endl;
        System::enteringServer(name);
        return true;
    }else{
        cout << "Servidor com esse nome já existe." << endl;
        return false;
    }
}

/**
 * @brief Define a descrição de um servidor.
 *
 * @param name O nome do servidor.
 * @param desc A nova descrição do servidor.
 */
void System::setServerDescription(string name, string desc){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers[i].setDescription(desc);
                cout << "Descrição do servidor '" << name;
                if(desc != ""){
                    cout << "' modificada!" << endl;
                }else{
                    cout << "' removida!" << endl;
                }
                
            }else{
                cout << "Você não pode alterar a descrição de um servidor que não foi criado por você." << endl;
            }
        }
    }
    if(found == false){
        cout << "Servidor '" << name << "' não existe." << endl;
    }
}

/**
 * @brief Define o código de convite de um servidor.
 *
 * @param name O nome do servidor.
 * @param ic O novo código de convite.
 */
void System::setServerInviteCode(string name, string ic){
    bool found = false;
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers[i].setInviteCode(ic);
                cout << "Código de convite do servidor '" << name;
                if(ic.length() != 0){
                    cout << "' modificado!" << endl;
                }else{
                    cout << "' removido!" << endl;
                }
                
            }else{
                cout << "Você não pode alterar o código de convite de um servidor que não foi criado por você." << endl;
            }
        }
    }
    if(found == false){
        cout << "Servidor '" << name << "'não existe." << endl;
    }
}

/**
 * @brief Lista os servidores disponíveis no sistema.
 */
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

/**
 * @brief Remove um servidor do sistema.
 *
 * @param name O nome do servidor a ser removido.
 */
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

/**
 * @brief Realiza a entrada de um usuário em um servidor.
 *
 * @param name O nome do server após o tratamento.
 * @param ic O invite-code após o tratamento.
 * @param parameter O comando de entrada, que contém o nome do servidor e pode conter o código de convite separados por espaço.
 * @return Verdadeiro se a entrada for bem-sucedida, falso caso contrário.
 */
bool System::enteringServer(string parameter){
    int spaces = 0; string name, ic; bool found = false;
    //começo do tratamento do parâmetro
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
    //fim do tratamento do parâmetro
    //começo da busca pelo servidor
    for(int i=0; i<servers.size(); i++){
        if(name == servers[i].getName()){
            found = true;
            if(ic == servers[i].getInviteCode() || currentLoggedInUser.getId() == servers[i].getOwnerId()){
                servers[i].enteringServer(currentLoggedInUser.getId());
                System::setCurrentServer(servers[i]);
                cout << "Entrou no servidor '"<< servers[i].getName() <<"' com sucesso." << endl;
                return true;
            }else if(ic == "" && servers[i].getInviteCode() != ""){
                cout << "Servidor requer código de convite." << endl;
            }else if(servers[i].getInviteCode() != "" && ic != "" && ic != ""){
                cout << "Código de convite incorreto. Verifique se os dados inseridos estão corretos e tente novamente." << endl;
            }
        }
    }
    //fim da busca pelo servidor
    if(found == false){
        cout << "Servidor não encontrado." << endl;
    }
    return false;
}

/**
 * @brief Realiza a saída de um servidor.
 */
void System::leavingServer(bool toprint){
    cout << "Saindo do servidor '" << currentServer.getName() << "'." << endl;
    System::setCurrentServer(Server());
    System::setCurrentChannel(Channel());
}

/**
 * @brief Lista os participantes do servidor atual.
 */
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
/**
 * Define o canal atual do sistema.
 * @param currentChannel O canal a ser definido como atual.
 */
void System::setCurrentChannel(Channel currentChannel){
    this->currentChannel = currentChannel;
}

/**
 * Cria um novo canal no servidor atual.
 * @param name O nome do novo canal.
 * @param isText Indica se o canal é um canal de texto (true) ou de voz (false).
 */
void System::newChannel(string name, bool isText){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            servers[i].addChannelToServer(name, isText);
        }
    }
}

/**
 * Imprime a lista de canais do servidor atual.
 */
void System::printChannels(){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            cout << "「 Lista de canais do servidor '" << servers[i].getName() << "' 」" << endl;
            servers[i].printChannels();
            cout << "「 Fim da lista 」" << endl;
        }
    }
}

/**
 * Entra em um canal especificado.
 * @param name O nome do canal a ser acessado.
 * @param changing Indica se a entrada está sendo realizada como uma mudança de canal.
 * @return true se o canal existir e a entrada for bem-sucedida, false caso contrário.
 */
bool System::enteringChannel(string name, bool changing){
    bool found;
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            found = servers[i].alExistChannel(name);
            if(found == true){
                if(changing == false){
                    currentChannel = servers[i].getChannel(name);
                    cout << "Entrou no canal '" << currentChannel.getName() << "'." << endl;
                }else{
                    string old = currentChannel.getName();
                    currentChannel = servers[i].getChannel(name);
                    string nova = currentChannel.getName();
                    if(old == nova){
                        cout << "Você já está no canal '" << currentChannel.getName() << "'." << endl;
                    }else{
                        cout << "Saindo do canal '" << old << "' e entrou no canal '" << nova << "'." << endl;
                    }
                }
            }else{
                cout << "Canal '" << name << "' não existe." << endl;
            }
        }
    }
    return found;
}

/**
 * Sai do canal atual.
 */
void System::leavingChannel(){
    cout << "Saindo do canal." << endl;
    System::setCurrentChannel(Channel());
}

/**
 * Envia uma mensagem para o canal atual.
 * @param date A data da mensagem.
 * @param content O conteúdo da mensagem.
 */
void System::sendingMessage(string date, string content){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            int sentBy = currentLoggedInUser.getId();
            servers[i].sendingMessage(date , sentBy, content, currentChannel.getName());
        }
    }
}

/**
 * Imprime as mensagens do canal atual.
 */
void System::printMessages(){
    for(int i=0; i<servers.size(); i++){
        if(currentServer.getName() == servers[i].getName()){
            if(currentChannel.getType() == "text"){
                string sentBy, datetime, content; int atualid;
                if(servers[i].getQuantMessages(currentChannel.getName()) != 0 && servers[i].getSpecificMessageContent(currentChannel.getName(), 0) == ""){
                    cout << "Sem mensagens para exibir." << endl;
                    return;
                }
                //cout << servers[i].getQuantMessages(currentChannel.getName()) << endl;
                for(int j=0; j<servers[i].getQuantMessages(currentChannel.getName()); j++){
                    atualid = servers[i].getSpecificMessageSentBy(currentChannel.getName(), j);
                    datetime = servers[i].getSpecificMessageDateTime(currentChannel.getName(), j);
                    content = servers[i].getSpecificMessageContent(currentChannel.getName(), j);
                    sentBy = getUserNameById(atualid);
                    cout << sentBy << "<" << datetime << ">: " << content << endl;
                }
            }else if(currentChannel.getType() == "voice"){
                if(servers[i].getLastMessageContent(currentChannel.getName()) == ""){
                    cout << "Sem mensagens para exibir." << endl;
                    return;
                }
                cout << getUserNameById(servers[i].getLastMessageSentBy(currentChannel.getName())) << "<" << servers[i].getLastMessageDateTime(currentChannel.getName()) << ">: " << servers[i].getLastMessageContent(currentChannel.getName()) << endl;
            }
        }
    }
}
//end channels