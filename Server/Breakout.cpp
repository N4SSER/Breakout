#include <GL/glut.h>
#include <iostream>
#include "Game.h"
#include "Wall.h"
#include "Painter.h"
#include "SocketServer.h"
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

    /* Game Here */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Wall::WIDTH,Wall::HEIGHT);
    glutCreateWindow("Breakout");
    glClearColor(256, 0, 256, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, Wall::WIDTH, Wall::HEIGHT, 0, -1.0, 1.0);
    glutDisplayFunc(display);
    timer();
    glutMainLoop();
}

