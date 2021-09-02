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
}
int main(int argc, char **argv) {
    client = new SocketClient;
    pthread_t thread;
    pthread_create(&thread,nullptr,clientRun,nullptr);
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
