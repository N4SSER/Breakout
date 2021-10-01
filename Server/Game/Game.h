/**
 * @file Game.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase de Game
 * @brief Clase la cual maneja gran parte de la logica y repeticion del juego
 * @date 30/9/2021
 */
#ifndef BREAKOUTLITE_GAME_H
#define BREAKOUTLITE_GAME_H
#include <list>
#include "Painter.h"
#include "Ball.h"
#include "Wall.h"
#include "Paddle.h"
#include "Brick.h"

class Game {
public:
    bool finished=false;
    /**
     *
     * @brief Metodo el cual se encarga de dibujar a las clases de Ball, Wall y de Paddle
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @param Painter
     */
    void draw(Painter &) const;
    /**
     *
     * @brief Metodo que hace un set de la posicion X de la barra del jugador.
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @param int x Posicion x
     */
    void setX(int x);
    /**
     * @brief Metodo que actualiza la informacion de las clases Paddle, Wall, Brick y Ball, ademas verifica
     * que cuando una bola sale por  la parte inferior de la pantalla se disminuya el tamaño de la barra
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    void tick();
    /**
     * @brief Singleton de la instancia del juego
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    static Game* getInstance();
    bool start = false;
    int level{};
    Ball ball_;
    int timesLosed=0;
    /**
     * @brief Metodo sencillo que maneja el estado de profundidad de las bolas
     * @param state Establece el estado de profundidad es decir si es true el modo profundidad esta activado y si
     * es falso el modo profundidad esta desactivado.
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    void Set_Deep(bool state);
    Wall wall_;
private:
    std:: list<Ball> balls;
    Game();
    int pB;
    inline static Game* gameI;
    Paddle paddle;
};


#endif //BREAKOUTLITE_GAME_H
