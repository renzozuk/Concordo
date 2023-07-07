#ifndef CHANNEL_H
#define CHANNEL_H

#include <vector>

using std::string;
using std::vector;

class Channel{
protected:
    string name, type;
    //the string type is an auxiliary temporary string, that string will be removed and the methods will be improved soon
public:
    Channel() {}
    ~Channel() {}
    Channel(string, string);    
    string getName();
    string getType();
    virtual void addMessageToChannel(string, int, string) {}
    virtual int getQuantMessages() {}
    virtual int getSentByElement(int) {}
    virtual string getDateTimeElement(int) {}
    virtual string getContentElement(int) {}
    virtual void setLastMessage(string, int, string) {}
    virtual int getSentBy() {}
    virtual string getDateTime() {}
    virtual string getContent() {}
};

#endif