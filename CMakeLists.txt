cmake_minimum_required(VERSION 3.16.3)
project(teste VERSION 0.1 LANGUAGES CXX )

include_directories( include )


add_executable( program
                src/main.cpp
                src/system.cpp
                src/user.cpp
                src/server.cpp
                src/channel.cpp
                src/textchannel.cpp
                src/voicechannel.cpp
                src/message.cpp )
