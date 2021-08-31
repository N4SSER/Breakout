#include <iostream>
#include "SocketClient.h"
SocketClient* client;
void * clientRun(void* obj){
    try{
        client->connect_client();
    }catch (string ex){
        cout<<ex<<endl;
    }
    pthread_exit(NULL);
}
int main() {
    client = new SocketClient;
    pthread_t thread;
    pthread_create(&thread,0,clientRun,NULL);
    string json;
    while(true){
        string &msn=json;
        cin>>msn;
        if(msn == "EXIT"){
            break;
        }
        client->send_message(json.c_str());
    }
    delete client;
    return 0;
}
