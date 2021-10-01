/**
 * @file Painter.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase del Painter
 * @brief Clase que contiene las disminsiones de la barra y de la bola, ademas define los colores que se pueden usar
 * en la interfaz grafica
 * @date 30/9/2021
 */
#ifndef BREAKOUTLITE_PAINTER_H
#define BREAKOUTLITE_PAINTER_H


class Painter {
public:
    enum Color { YELLOW, GREEN, ORANGE, RED, WHITE, BLACK };
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo que define las dimensiones de la barra
     * @param x1 Posicion x de la barra
     * @param y1 Posicion y de la barra
     * @param x2 Largo de la barra
     * @param y2 Ancho de la barra
     */
    static void bar(float x1,  float y1, float x2, float y2);
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo que define las dimensiones de la bola
     * @param x
     * @param y
     */
    static void ball(float x, float y);
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo que contiene los colores del juego
     * @param Color
     */
    static void setColor(Color);
};


#endif //BREAKOUTLITE_PAINTER_H
