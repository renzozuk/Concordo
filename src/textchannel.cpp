#include <iostream>
#include <textchannel.h>

TextChannel::TextChannel(string name){
    this->name = name;
}

void TextChannel::addMessageToChannel(string date, int sentBy, string content){
    messages.push_back(Message(date, sentBy, content));
}

int TextChannel::getQuantMessages(){
    return messages.size();
}

int TextChannel::getSentByElement(int i){
    if(messages[i].getContent() == ""){
        return 0;
    }else{
        return messages[i].getSentBy();
    }
}

string TextChannel::getDateTimeElement(int i){
    if(messages[i].getContent() == ""){
        return "";
    }else{
        return messages[i].getDateTime();
    }
}

string TextChannel::getContentElement(int i){
    if(messages[i].getContent() == ""){
        return "";
    }else{
        return messages[i].getContent();
    }
}