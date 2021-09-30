/**
 * @file Force.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @brief Este struct calcula la fuerza resultante de la bola cuando sucede una colision esta fuerza de empuje hace que la bola
 * aumente de velocidad
 * @struct
 */
#ifndef BREAKOUTLITE_FORCE_H
#define BREAKOUTLITE_FORCE_H

struct Force
{
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @param x
     * @param y
     * @brief Construtor del struct
     */
    Force(float x, float y);
    float x, y;
    /**
     * @operator Es un operador que calcula la fuerza resultante de la bola cuando choca con la pared de la ventana
     * o cuando colisiona con un bloque
     * @param f
     * @return
     */
    const Force &operator+=(Force f);
};



#endif //BREAKOUTLITE_FORCE_H
