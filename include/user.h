#ifndef USER_H
#define USER_H

#include <string>
using std::string;

class User{
private:
    int id;
    string email, password, name;
public:
    User() {}
    ~User() {}
    User(int y, const string& e, const string& p, const string& n) : id(y), email(e), password(p), name(n) {};
    int getId() const;
    string getEmail() const;
    string getPassword() const;
    string getName() const;
};

#endif