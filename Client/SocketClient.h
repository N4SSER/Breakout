//
// Created by n4ssser on 30/8/21.
//

#ifndef CLIENT_SOCKETCLIENT_H
#define CLIENT_SOCKETCLIENT_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;
class SocketClient {
public:
    SocketClient();
    void connect_client();
    void send_message(const char* msn) const;

private:
    int descriptor;
    sockaddr_in info;
    static void* controller(void* obj);
};


#endif //CLIENT_SOCKETCLIENT_H
