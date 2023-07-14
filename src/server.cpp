#include <iostream>
#include <server.h>

using std::cout;
using std::endl;

void Server::ChannelsDestroyer() {
    for (Channel* chnl : channels) {
        if (TextChannel* tc = dynamic_cast<TextChannel*>(chnl)) {
            delete tc;
        } else if (VoiceChannel* vc = dynamic_cast<VoiceChannel*>(chnl)) {
            delete vc;
        }
    }
}

int Server::getOwnerId(){
    return ownerid;
}

string Server::getName(){
    return name;
}

string Server::getDescription(){
    return description;
}

string Server::getInviteCode(){
    return invitecode;
}

void Server::setDescription(string description){
    this->description = description;
}

void Server::setInviteCode(string invitecode){
    this->invitecode = invitecode;
}

void Server::enteringServer(int id){
    bool alinserver = false;
    for(int i=0; i < membersid.size(); i++){
        if(id == membersid[i]){
            alinserver = true;
        }
    }
    if(alinserver == false){
        membersid.push_back(id);
    }
}

int Server::getQuantMembers(){
    return membersid.size();
}

int* Server::getListMembers(){
    int* msid = new int[Server::getQuantMembers()];
    for(int i=0; i < membersid.size(); i++){
        msid[i] = membersid[i];
    }
    return msid;
}

int Server::getSpecificMemberIdByPosition(int pos){
    return membersid[pos];
}

//start channels
bool Server::alExistChannel(string name){
    bool alexist = false;
    for(const auto& chnl: channels){
        if(chnl->getName() == name){
            alexist = true;
        }
    }
    return alexist;
}

void Server::addChannelToServer(string name, bool isText, bool toPrint){
    bool alexist; alexist = Server::alExistChannel(name);
    if(alexist == true){
        if(toPrint == true){
            cout << "Canal '" << name << "' já existe." << endl;
        }
        return;
    }else{
        if(isText == true){
            channels.push_back(new TextChannel(name));
            if(toPrint == true){
                cout << "Canal de texto '" << name << "' criado." << endl;
            }
        }else{
            channels.push_back(new VoiceChannel(name));
            if(toPrint == true){
                cout << "Canal de voz '" << name << "' criado." << endl;
            }
        }
    }
}

int Server::getQuantChannels(){
    return channels.size();
}

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

Channel Server::getChannel(string name){
    for(const auto& chnl: channels){
        if(chnl->getName() == name){
            return* chnl;
        }
    }
    return Channel();
}

string Server::getChannelNameByPosition(int pos){
    return channels[pos]->getName();
}

void Server::sendingMessage(string date, int sentBy, string content, string currentChannelName){
    for(const auto& chnl: channels){
        if(Server::getChannelType(chnl->getName()) == "text" && chnl->getName() == currentChannelName){
            chnl->addMessageToChannel(date, sentBy, content);
        }else if(Server::getChannelType(chnl->getName()) == "voice" && chnl->getName() == currentChannelName){
            chnl->setLastMessage(date, sentBy, content);
        }
    }
}

int Server::getQuantMessages(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getQuantMessages();
        }
    }
    return 0;
}

int Server::getSpecificMessageSentBy(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getSentByElement(position);
        }
    }
}

string Server::getSpecificMessageDateTime(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getDateTimeElement(position);
        }
    }
}

string Server::getSpecificMessageContent(string currentChannelName, int position){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getContentElement(position);
        }
    }
}

int Server::getLastMessageSentBy(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getSentBy();
        }
    }
}

string Server::getLastMessageDateTime(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getDateTime();
        }
    }
}

string Server::getLastMessageContent(string currentChannelName){
    for(const auto& chnl: channels){
        if(chnl->getName() == currentChannelName){
            return chnl->getContent();
        }
    }
}
//end channels