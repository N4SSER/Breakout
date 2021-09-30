/**
 * @file Wall.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase Wall
 * @brief Contiene las funciones y caracteristicas de la clase Wall.
 * @date 30/9/2021
 */
#include <vector>
#include "Brick.h"
#include "Ball.h"
#include "Force.h"
#include "Painter.h"

#ifndef BREAKOUTLITE_WALL_H
#define BREAKOUTLITE_WALL_H


class Wall {
    public:
    enum { ROWS_COUNT = 16,
        COLS_COUNT = 8 * 3 };
    enum { WIDTH = ROWS_COUNT * Brick::WIDTH,
        HEIGHT = COLS_COUNT * Brick::HEIGHT };
    /**
     * @brief Este constructor contiene y crea el Vector de Bricks
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    Wall();
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Este metodo primero recorre la el vector de Bricks para que cada uno sea dibujado en pantalla
     * @param Painter
     */
    void draw(Painter &) const;
    /**
     * @brief Se chequea las colisiones de las bola con los bricks
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     *
     */
    Force tick(const Ball &);
    int points;
public:
    /**
     * @brief Hace un get de los puntos del jugador
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */

    int getpts() const;
    typedef std::vector<Brick> Bricks;
    Bricks bricks_;
};


#endif //BREAKOUTLITE_WALL_H
