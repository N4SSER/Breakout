#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include "Game/Game.h"
#include "Game/Wall.h"
#include "Game/Painter.h"
#include "Game/SocketServer.h"
SocketServer* server;
void * serverRun(void* obj){
    try{
        server->run();
    }
    catch (string ex){
        cout<<ex<<endl;
    }
    pthread_exit(nullptr);
}
Game* game = Game::getInstance();
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    Painter p;
    game->draw(p);
    glutSwapBuffers();
}

void timer(int = 0)
{
    if(game->finished){
        glutLeaveMainLoop();
        server->send_message("Oops!, you've losed \n your score:");
        char s = game->wall_.score;
        string ss = to_string(s);
        server->send_message(ss.c_str());
    }
    for (int i = 0; i < 1.0 / 25 / Ball::DT; ++i)
        game->tick();
    display();
    glutTimerFunc(1000 / 25, timer, 0);
}

int main(int argc, char **argv)
{
    server= new SocketServer;
    pthread_t thread;
    pthread_create(&thread, nullptr,serverRun,nullptr);
    pthread_detach(thread);
    while (!game->start){
        //Waiting for login
    }
    /* Game Here */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Wall::WIDTH,Wall::HEIGHT);
    glutCreateWindow("Crazy Breakout!");
    glClearColor(256, 0, 256, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Wall::WIDTH, Wall::HEIGHT, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}

