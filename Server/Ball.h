/**
 * @file Ball.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase de la bola
 * @brief Contiene las funciones y caracteristicas de la bola.
 * @date 30/9/2021
 */
#include "Force.h"
#include "Painter.h"
#ifndef BREAKOUTLITE_BALL_H
#define BREAKOUTLITE_BALL_H

extern int ball_speed_x;
extern int ball_speed_y;
class Ball {
public:
    constexpr static const float DT = 0.0005;
    Ball();
    /**
     *
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Esta metodo hace el set del nivel de profundidad
     * @param lvl Indica el nivel de profundidad
     * @date 9/30/2021
     */
    void setDeepLvl(int lvl);
    /**
     *
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Esta metodo hace el get del nivel de profundidad
     * @date 9/30/2021
     */
    int getDeepLvl() const;
    /**
     *
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Esta metodo aumenta el nivel de profundidad de la bola
     * @date 9/30/2021
     */
    void increaseDeep();

    /**
     *
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Esta metodo dibuja la bola en la interfaz grafica
     * @date 9/30/2021
     * @param Painter Esta parametro sirve para dibujar la bola en pantalla
     */
    void draw(Painter &) const;
    
    [[nodiscard]] float x() const { return x_; }
    [[nodiscard]] float y() const { return y_; }
    /**
     *
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Esta metodo hace que la bola rebote cuando se detecta una colisión
     * @date 9/30/2021
     * @param Force Este operador hace los calculos de la fuerza de rebote.
     */
    void tick(Force);
private:
    int lvl;
    float x_;
    float y_;
    float vx_;
    float vy_;
};


#endif //BREAKOUTLITE_BALL_H
