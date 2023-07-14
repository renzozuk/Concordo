#ifndef SYSTEM_H
#define SYSTEM_H

#include <user.h>
#include <server.h>

using std::vector;

class System{
private:
    vector<User> users; vector<Server> servers;
    User currentLoggedInUser; Server currentServer; Channel currentChannel;
    //start disk-data
    void saveUsers(); void saveServers();
    void loadUsers(); void loadServers();
    //end disk-data
public:
    System() {}
    ~System() {}
    void ChannelsDestroyer();
    int getIntByString(string);
    
    //start users
    void setLoggedInUser(User);
    //User getLoggedInUser();
    void setLoggedInUserById(int);
    string getUserNameById(int);
    bool alExistUser(string);
    void addUserToSystem(const string&, const string&, const string&);
    bool loggingIn(string, string);
    void disconnect();
    //end users

    //start servers
    void setCurrentServer(Server);
    bool alExistServer(string);
    bool addServerToSystem(string, bool);
    void setServerDescription(string, string, bool);
    void setServerInviteCode(string, string, bool);
    void listServers();
    bool enteringServer(string, string, bool);
    void removeServer(string);
    void leavingServer(bool);
    void listParticipants();
    //end servers

    //start channels
    void setCurrentChannel(Channel);
    void newChannel(string, bool, bool);
    void printChannels();
    bool enteringChannel(string, bool);
    void leavingChannel();
    void sendingMessage(string, string);
    void printMessages();
    //end channels

    //start disk-data
    void save();
    void load();
    //end disk-data
};

#endif