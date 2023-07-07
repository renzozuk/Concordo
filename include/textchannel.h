#ifndef TEXTCHANNEL_H
#define TEXTCHANNEL_H

#include <channel.h>
#include <message.h>

class TextChannel: public Channel{
private:
    vector<Message> messages;
public:
    TextChannel() {}
    ~TextChannel() {}
    TextChannel(string, string);
    //start messages
    void addMessageToChannel(string, int, string);
    int getQuantMessages();
    int getSentByElement(int);
    string getDateTimeElement(int);
    string getContentElement(int);
    //end messages
};

#endif