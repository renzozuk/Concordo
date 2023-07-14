#include <iostream>
#include <voicechannel.h>

using std::cout;
using std::endl;

VoiceChannel::VoiceChannel(string name){
    this->name = name;
}

void VoiceChannel::setLastMessage(string date, int sentBy, string content){
    lastMessage = Message(date, sentBy, content);
}

int VoiceChannel::getSentBy(){
    if(lastMessage.getContent() == ""){
        return 0;
    }else{
        return lastMessage.getSentBy();
    }
}

string VoiceChannel::getDateTime(){
    if(lastMessage.getContent() == ""){
        return "";
    }else{
        return lastMessage.getDateTime();
    }
}

string VoiceChannel::getContent(){
    if(lastMessage.getContent() == ""){
        return "";
    }else{
        return lastMessage.getContent();
    }
}