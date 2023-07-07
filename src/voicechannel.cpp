/**
 * @file voicechannel.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe VoiceChannel.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <voicechannel.h>

using std::cout;
using std::endl;

/**
 * Construtor da classe VoiceChannel.
 * @param name O nome do canal.
 * @param type O tipo do canal (voice).
 */
VoiceChannel::VoiceChannel(string name, string type){
    this->name = name;
    this->type = type;
}

/**
 * Define a última mensagem enviada no canal de voz.
 * @param date A data da mensagem.
 * @param sentBy O remetente da mensagem.
 * @param content O conteúdo da mensagem.
 */
void VoiceChannel::setLastMessage(string date, int sentBy, string content){
    lastMessage = Message(date, sentBy, content);
}

/**
 * Obtém o remetente da última mensagem enviada no canal de voz.
 * @return O remetente da última mensagem.
 */
int VoiceChannel::getSentBy(){
    if(lastMessage.getContent() == ""){
        return 0;
    }else{
        return lastMessage.getSentBy();
    }
}

/**
 * Obtém a data e hora da última mensagem enviada no canal de voz.
 * @return A data e hora da última mensagem.
 */
string VoiceChannel::getDateTime(){
    if(lastMessage.getContent() == ""){
        return "";
    }else{
        return lastMessage.getDateTime();
    }
}

/**
 * Obtém o conteúdo da última mensagem enviada no canal de voz.
 * @return O conteúdo da última mensagem.
 */
string VoiceChannel::getContent(){
    if(lastMessage.getContent() == ""){
        return "";
    }else{
        return lastMessage.getContent();
    }
}