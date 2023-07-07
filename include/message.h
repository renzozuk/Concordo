#ifndef MESSAGE_H
#define MESSAGE_H

using std::string;

class Message{
private:
    string datetime;
    int sentBy; //user's id
    string content;
public:
    Message() {}
    ~Message() {}
    Message(string, int, string);
    string getDateTime();
    int getSentBy();
    string getContent();
};

#endif