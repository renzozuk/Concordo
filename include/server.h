#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <vector>
#include <textchannel.h>
#include <voicechannel.h>

using std::string;
using std::vector;

class Server{
private:
    int ownerid;
    string name, description, invitecode;
    vector<int> membersid;
    vector<Channel*> channels;
public:
    Server() {}
    ~Server() {}
    void ChannelsDestroyer();
    Server(int o, const string& n) : ownerid(o), name(n) {};
    int getOwnerId();
    string getName();
    string getDescription();
    string getInviteCode();
    void setDescription(string);
    void setInviteCode(string);
    void enteringServer(int);
    int getQuantMembers();
    int* getListMembers();
    int getSpecificMemberIdByPosition(int);
    //start channels//
    bool alExistChannel(string);
    void addChannelToServer(string, bool, bool);
    void printChannels();
    int getQuantChannels();
    string getChannelType(string);
    Channel getChannel(string);
    string getChannelNameByPosition(int);
    void sendingMessage(string, int, string, string);
    int getQuantMessages(string);
    int getSpecificMessageSentBy(string, int);
    string getSpecificMessageDateTime(string, int);
    string getSpecificMessageContent(string, int);
    int getLastMessageSentBy(string);
    string getLastMessageDateTime(string);
    string getLastMessageContent(string);
    //end channels//
};

#endif