
#include "SocketServer.h"
#include "Game.h"
SocketServer::SocketServer() {}
Game* g = Game::getInstance();
int x = Wall::WIDTH/2;
bool SocketServer::create_socket() {
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor<0){
        return false;
    }
    info.sin_family =AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool SocketServer::link_kernel() {
    if(bind(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))<0){
        return false;
    }
    listen(descriptor,1);
    return true;
}

void SocketServer::run() {
    if(!create_socket()){
        throw string("Can not create socket");
    }
    if(!link_kernel()){
        throw string("can not link kernel");
    }
    while (true){
        dataSocket data;
        socklen_t  t = sizeof(data.info);
        cout<<"Waiting for clients"<<endl;
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&t);
        if(data.descriptor<0){
            throw string ("Can not accept client");
        } else{
            clients.push_back(data.descriptor);
            cout<<"connected!"<<endl;
            pthread_t thread;
            pthread_create(&thread,nullptr,SocketServer::client_controller,(void*)&data);
            pthread_detach(thread);
        }
    }
    close(descriptor);
}

void *SocketServer::client_controller(void *obj) {
    auto* data = (dataSocket*)obj;
    while (true){
        string message;
        char buffer[1024] ={0};
        while(true){
            memset(buffer,0,1024);
            int bytes = recv(data->descriptor,buffer,1024,0);
            message.append(buffer,bytes);
            if(bytes<1){
                close(data->descriptor);
                pthread_exit(nullptr);
            }
            if(bytes<1024){
                break;
            }
        }
        ctrlC(message);
    }
    close(data->descriptor);
    pthread_exit(NULL);
}

void SocketServer::send_message(const char *msn) {
    for(auto&client:clients){
        send(client,msn, strlen(msn),0);
    }
}

void SocketServer::ctrlC(string msg) {
    if(msg == "a"){
        x -=20;
    }
    if(msg == "d"){
        x +=20;
    }
    g->setX(x);
}

