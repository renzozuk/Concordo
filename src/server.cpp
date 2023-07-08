/**
 * @file server.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe Server.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <server.h>

using std::cout;
using std::endl;

/**
 * @brief Destrutor de canais.
 * 
 */
void Server::ChannelsDestroyer() {
    for (Channel* chnl : channels) {
        if (TextChannel* tc = dynamic_cast<TextChannel*>(chnl)) {
            delete tc;
        } else if (VoiceChannel* vc = dynamic_cast<VoiceChannel*>(chnl)) {
            delete vc;
        }
    }
    //removido temporariamente
    //se não for mais necessário, será removido permanentemente
    /*for(Channel *channel : channels){
        delete channel;
    }*/
}

/**
 * @brief Obtém o ID do proprietário do servidor.
 * @return O ID do proprietário do servidor.
 */
int Server::getOwnerId(){
    return ownerid;
}

/**
 * @brief Obtém o nome do servidor.
 * @return O nome do servidor.
 */
string Server::getName(){
    return name;
}

/**
 * @brief Obtém o código de convite do servidor.
 * @return O código de convite do servidor.
 */
string Server::getInviteCode(){
    return invitecode;
}

/**
 * @brief Define a descrição do servidor.
 * @param description A descrição do servidor.
 */
void Server::setDescription(string description){
    this->description = description;
}

/**
 * @brief Define o código de convite do servidor.
 * @param invitecode O código de convite do servidor.
 */
void Server::setInviteCode(string invitecode){
    this->invitecode = invitecode;
}

/**
 * @brief Adiciona um usuário ao servidor.
 * @param id O ID do usuário a ser adicionado.
 */
void Server::enteringServer(int id){
    bool alinserver = false;
    for(int i=0; i<membersid.size(); i++){
        if(id == membersid[i]){
            alinserver = true;
        }
    }
    if(alinserver == false){
        membersid.push_back(id);
    }
}

/**
 * @brief Obtém a quantidade de membros no servidor.
 * @return A quantidade de membros no servidor.
 */
int Server::getQuantMembers(){
    return membersid.size();
}

/**
 * @brief Obtém uma lista de ID dos membros do servidor.
 * @return Um ponteiro para um array de inteiros contendo os IDs dos membros.
 */
int* Server::getListMembers(){
    int quant = Server::getQuantMembers();
    int* msid = new int[quant];
    for(int i=0; i<membersid.size(); i++){
        msid[i] = membersid[i];
    }
    return msid;
}

//start channels
/**
 * Verifica se um canal com o nome especificado já existe no servidor.
 *
 * @param name O nome do canal a ser verificado.
 * @return true se o canal existe, false caso contrário.
 */
bool Server::alExistChannel(string name){
    bool alexist = false;
    for(const auto& chnl : channels){
        if(chnl->getName() == name){
            alexist = true;
        }
    }
    return alexist;
}

/**
 * Adiciona um novo canal ao servidor.
 *
 * @param name O nome do canal a ser adicionado.
 * @param isText Um valor booleano indicando se o canal é de texto.
 */
void Server::addChannelToServer(string name, bool isText){
    bool alexist; alexist = Server::alExistChannel(name);
    if(alexist == true){
        cout << "Canal '" << name << "' já existe." << endl;
        return;
    }else{
        if(isText == true){
            channels.push_back(new TextChannel(name));
            cout << "Canal de texto '" << name << "' criado." << endl;
        }else{
            channels.push_back(new VoiceChannel(name));
            cout << "Canal de voz '" << name << "' criado." << endl;
        }
    }
}

/**
 * Imprime os canais do servidor.
 */
void Server::printChannels(){
    //Channel* addedObject = channels.back();
    cout << "#canais de texto" << endl;
    for(Channel* chnl: channels) {
        if(TextChannel* tc = dynamic_cast<TextChannel*>(chnl)){
            cout << tc->getName() << endl;
        }
    }
    cout << "#canais de voz" << endl;
    for(Channel* chnl: channels){
        if(VoiceChannel* vc = dynamic_cast<VoiceChannel*>(chnl)){
            cout << vc->getName() << endl;
        }
    }
}

string Server::getChannelType(string currentChannelName){
    for(Channel* chnl: channels){
        if(chnl->getName() == currentChannelName){
            if(TextChannel* tc = dynamic_cast<TextChannel*>(chnl)){
                return "text";
            }else if(VoiceChannel* vc = dynamic_cast<VoiceChannel*>(chnl)){
                return "voice";
            }
        }
    }
}

/**
 * Obtém um canal específico do servidor com base no nome.
 * @param name O nome do canal a ser obtido.
 * @return O canal correspondente, ou um canal vazio se não for encontrado.
 */
Channel Server::getChannel(string name){
    for(const auto& chnl: channels){
        if(chnl->getName() == name){
            return* chnl;
        }
    }
    return Channel();
}

/**
 * Envia uma mensagem para o canal atual especificado.
 * @param date A data da mensagem.
 * @param sentBy O remetente da mensagem.
 * @param content O conteúdo da mensagem.
 * @param currentChannelName O nome do canal atual.
 */
void Server::sendingMessage(string date, int sentBy, string content, string currentChannelName){
    for(const auto& chnl: channels){
        if(Server::getChannelType(chnl->getName()) == "text" && chnl->getName() == currentChannelName){
            chnl->addMessageToChannel(date, sentBy, content);
        }else if(Server::getChannelType(chnl->getName()) == "voice" && chnl->getName() == currentChannelName){
            chnl->setLastMessage(date, sentBy, content);
        }
    }
}

/**
 * Obtém a quantidade de mensagens no canal atual especificado.
 * @param currentChannelName O nome do canal atual.
 * @return A quantidade de mensagens no canal.
 */
int Server::getQuantMessages(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getQuantMessages();
        }
    }
}

/**
 * Obtém o remetente de uma mensagem específica no canal atual.
 * @param currentChannelName O nome do canal atual.
 * @param position A posição da mensagem na lista.
 * @return O remetente da mensagem.
 */
int Server::getSpecificMessageSentBy(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getSentByElement(position);
        }
    }
}

/**
 * Obtém a data e hora de uma mensagem específica no canal atual.
 * @param currentChannelName O nome do canal atual.
 * @param position A posição da mensagem na lista.
 * @return A data e hora da mensagem.
 */
string Server::getSpecificMessageDateTime(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getDateTimeElement(position);
        }
    }
}

/**
 * Obtém o conteúdo de uma mensagem específica no canal atual.
 * @param currentChannelName O nome do canal atual.
 * @param position A posição da mensagem na lista.
 * @return O conteúdo da mensagem.
 */
string Server::getSpecificMessageContent(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getContentElement(position);
        }
    }
}

/**
 * Obtém o remetente da última mensagem enviada ao canal atual.
 * @param currentChannelName O nome do canal atual.
 * @return O remetente da última mensagem.
 */
int Server::getLastMessageSentBy(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getSentBy();
        }
    }
}

/**
 * Obtém a data e hora da última mensagem enviada ao canal atual.
 * @param currentChannelName O nome do canal atual.
 * @return A data e hora da última mensagem.
 */
string Server::getLastMessageDateTime(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getDateTime();
        }
    }
}

/**
 * Obtém o conteúdo da última mensagem enviada ao canal atual.
 * @param currentChannelName O nome docanal atual.
 * @return O conteúdo da última mensagem.
 */
string Server::getLastMessageContent(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getContent();
        }
    }
}
//end channels