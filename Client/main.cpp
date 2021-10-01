#include <iostream>
#include <GL/glut.h>
#include "SocketClient.h"
SocketClient* client;
void * clientRun(void* obj){
    try{
        client->connect_client();
    }catch (string ex){
        cout<<ex<<endl;
    }
    pthread_exit(nullptr);
}
void KeyPressed(unsigned char Key, int x, int y){

    if(Key == 'a'){
        client->send_message("a");
    }
    if(Key == 'd'){
        client->send_message("d");
    }
    if(Key == 'w')
    {
        client->send_message("w");
    }
    if(Key == 's')
    {
        client->send_message("s");
    }
}
int main(int argc, char **argv) {
    client = new SocketClient;
    pthread_t thread;
    pthread_create(&thread,nullptr,clientRun,nullptr);
    cout<<"Enter your name"<<endl;
    string msn;
    cin>>msn;
    client->send_message(msn.c_str());
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(0,0);
    glutCreateWindow("Client");
    glClearColor(0, 0, 0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 0, 0, 0, -1.0, 1.0);
    glutKeyboardFunc(KeyPressed);
    glutMainLoop();
    delete client;
    return 0;
}
