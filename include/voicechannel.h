#ifndef VOICECHANNEL_H
#define VOICECHANNEL_H

#include <channel.h>
#include <message.h>

class VoiceChannel: public Channel{
private:
    Message lastMessage;
public:
    VoiceChannel() {}
    ~VoiceChannel() {}
    VoiceChannel(string, string);
    //start messages
    void setLastMessage(string, int, string);
    int getSentBy();
    string getDateTime();
    string getContent();
    //end messages
};

#endif