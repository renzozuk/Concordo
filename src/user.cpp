#include <iostream>
#include <user.h>

int User::getId() const{
    return id;
}

string User::getEmail() const{
    return email;
}

string User::getPassword() const{
    return password;
}

string User::getName() const{
    return name;
}