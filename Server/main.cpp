#include <iostream>
#include "SocketServer.h"
SocketServer* server;
void * serverRun(void* obj){
    try{
        server->run();
    }
    catch (string ex){
        cout<<ex<<endl;
    }
    pthread_exit(NULL);
}
int main() {
    server= new SocketServer;
    pthread_t thread;
    pthread_create(&thread,0,serverRun,NULL);
    pthread_detach(thread);
    string json;
    while (true){
        string &msn=json;
        cin>>msn;
        if(msn=="EXIT"){
            break;
        }
        server->send_message(json.c_str());
    }
    delete server;
    return 0;
}
