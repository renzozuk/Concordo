#include <iostream>
#include <message.h>

Message::Message(string datetime, int sentBy, string content){
    this->datetime = datetime;
    this->sentBy = sentBy;
    this->content = content;
}

string Message::getDateTime(){
    return datetime;
}

int Message::getSentBy(){
    return sentBy;
}

string Message::getContent(){
    return content;
}