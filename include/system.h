#ifndef SYSTEM_H
#define SYSTEM_H

#include <user.h>
#include <server.h>

using std::vector;

class System{
private:
    vector<User> users; vector<Server> servers;
    User currentLoggedInUser; Server currentServer; Channel currentChannel;
public:
    System() {}
    ~System() {}
    void ChannelsDestroyer();
    
    //start users
    User getLoggedInUser();
    void setLoggedInUser(User);
    string getUserNameById(int);
    bool alExistUser(string);
    void addUserToSystem(const string&, const string&, const string&);
    bool loggingIn(string, string);
    void disconnect();
    //end users

    //start servers
    Server getCurrentServer();
    void setCurrentServer(Server);
    bool alExistServer(string);
    bool addServerToSystem(string);
    void setServerDescription(string, string);
    void setServerInviteCode(string, string);
    void listServers();
    bool enteringServer(string);
    void removeServer(string);
    void leavingServer(bool);
    void listParticipants();
    //end servers

    //start channels
    void setCurrentChannel(Channel);
    void newChannel(string, bool);
    void printChannels();
    bool enteringChannel(string, bool);
    void leavingChannel();
    void sendingMessage(string, string);
    void printMessages();
    //end channels
};

#endif