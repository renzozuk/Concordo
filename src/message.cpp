/**
 * @file message.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe Message.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <message.h>

/**
 * Construtor da classe Message.
 * @param datetime A data e hora da mensagem.
 * @param sentBy O remetente da mensagem.
 * @param content O conteúdo da mensagem.
 */
Message::Message(string datetime, int sentBy, string content){
    this->datetime = datetime;
    this->sentBy = sentBy;
    this->content = content;
}

/**
 * Obtém a data e hora da mensagem.
 * @return A data e hora da mensagem.
 */
string Message::getDateTime(){
    return datetime;
}

/**
 * Obtém o remetente da mensagem.
 * @return O remetente da mensagem.
 */
int Message::getSentBy(){
    return sentBy;
}

/**
 * Obtém o conteúdo da mensagem.
 * @return O conteúdo da mensagem.
 */
string Message::getContent(){
    return content;
}