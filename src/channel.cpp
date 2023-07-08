/**
 * @file channel.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe Channel.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <channel.h>

/**
 * Construtor da classe Channel.
 * @param name O nome do canal.
 * @param type O tipo do canal (text ou voice).
 */
Channel::Channel(string name){
    this->name = name;
}

/**
 * Obtém o nome do canal.
 * @return O nome do canal.
 */
string Channel::getName(){
    return name;
}

/**
 * Obtém o tipo do canal.
 * @return O tipo do canal (text ou voice).
 */
/*string Channel::getType(){
    return type;
}*/