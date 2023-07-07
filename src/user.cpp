/**
 * @file user.cpp
 * @author Renzo Zukeram
 * @brief Implementação da classe User.
 * @version 2.0
 * @date 2023-07-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <user.h>

/**
 * @brief Obtém o ID do usuário.
 * @return O ID do usuário.
 */
int User::getId() const{
    return id;
}

/**
 * @brief Obtém o email do usuário.
 * @return O email do usuário.
 */
string User::getEmail() const{
    return email;
}

/**
 * @brief Obtém a senha do usuário.
 * @return A senha do usuário.
 */
string User::getPassword() const{
    return password;
}

/**
 * @brief Obtém o nome do usuário.
 * @return O nome do usuário.
 */
string User::getName() const{
    return name;
}