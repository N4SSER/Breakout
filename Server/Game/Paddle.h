/**
 * @file Paddle.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase de la barra del jugador
 * @brief Contiene las funciones y caracteristicas de la barra.
 * @date 30/9/2021
 */
#ifndef BREAKOUTLITE_PEDAL_H
#define BREAKOUTLITE_PEDAL_H


#include "Painter.h"
#include "Force.h"
#include "Ball.h"
extern int WidthofPaddle;
class Paddle {
public:
    enum { WIDTH = 60 };
    //int WidthofPaddle=60; //Aumentar de tamano
    /**
     * @brief Constructor de la barra
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    Paddle();
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo el cual dibuja la barra en pantalla
     * @param Painter
     */
    void draw(Painter &) const;
    /**
     * @brief Verifica la colisiones que sucede entre la barra del jugador y las bolas y cuando se detecta una colision
     * hace que la bola rebote hacia arriba.
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @return Fuerza resultante
     */
    Force tick(const Ball &) const;
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo que hace el set de la posicion X del jugador
     * @param x
     */
    void setX(int x);
private:
    int x_;
};


#endif //BREAKOUTLITE_PEDAL_H
