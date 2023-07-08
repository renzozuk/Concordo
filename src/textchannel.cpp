/**
 * @file textchannel.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe TextChannel.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <textchannel.h>

/**
 * Construtor da classe TextChannel.
 * @param name O nome do canal.
 * @param type O tipo do canal (text).
 */
TextChannel::TextChannel(string name){
    this->name = name;
}

/**
 * Adiciona uma mensagem ao canal de texto.
 * @param date A data da mensagem.
 * @param sentBy O remetente da mensagem.
 * @param content O conteúdo da mensagem.
 */
void TextChannel::addMessageToChannel(string date, int sentBy, string content){
    messages.push_back(Message(date, sentBy, content));
}

/**
 * Obtém a quantidade de mensagens no canal de texto.
 * @return A quantidade de mensagens no canal.
 */
int TextChannel::getQuantMessages(){
    return messages.size();
}

/**
 * Obtém o remetente de uma mensagem específica no canal de texto.
 * @param i A posição da mensagem na lista.
 * @return O remetente da mensagem.
 */
int TextChannel::getSentByElement(int i){
    if(messages[i].getContent() == ""){
        return 0;
    }else{
        return messages[i].getSentBy();
    }
}

/**
 * Obtém a data e hora de uma mensagem específica no canal de texto.
 * @param i A posição da mensagem na lista.
 * @return A data e hora da mensagem.
 */
string TextChannel::getDateTimeElement(int i){
    if(messages[i].getContent() == ""){
        return "";
    }else{
        return messages[i].getDateTime();
    }
}

/**
 * Obtém o conteúdo de uma mensagem específica no canal de texto.
 * @param i A posição da mensagem na lista.
 * @return O conteúdo da mensagem.
 */
string TextChannel::getContentElement(int i){
    if(messages[i].getContent() == ""){
        return "";
    }else{
        return messages[i].getContent();
    }
}