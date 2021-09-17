
#include "SocketClient.h"

SocketClient::SocketClient() {}

void SocketClient::connect_client() {
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor<0){
        cout<<"Can't create the socket"<<endl;
    }
    info.sin_family =AF_INET;
    info.sin_addr.s_addr = inet_addr("192.168.1.12");
    info.sin_port = ntohs(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    if(connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))<0){
        cout<<"Can't connect to server"<<endl;
    }
    cout<<"We're in!"<<endl;
    pthread_t thread;
    pthread_create(&thread,0,SocketClient::controller,(void*) this);
    pthread_detach(thread);
}

void *SocketClient::controller(void *obj) {
    auto* c = (SocketClient*)obj;
    while (true){
        string message;
        char buffer[1024] ={0};
        while(true){
            memset(buffer,0,1024);
            int bytes = recv(c->descriptor,buffer,1024,0);
            message.append(buffer,bytes);
            if(bytes<1){
                close(c->descriptor);
                pthread_exit(nullptr);
            }
            if(bytes<1024){
                break;
            }
        }
        cout<<message<<endl;
    }
    close(c->descriptor);
    pthread_exit(NULL);
}

void SocketClient::send_message(const char *msn) const {
    send(descriptor,msn,strlen(msn),0);
}
