#include <iostream>
#include <channel.h>

Channel::Channel(string name){
    this->name = name;
}

string Channel::getName(){
    return name;
}