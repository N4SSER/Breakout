/**
 * @file Brick.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @brief Contiene todas las caracteristicas y funcionalidades de los bloques,
 * es decir esta clase contiene a los bloques comunes,dobles, triples, internos, profundos y Sorpresas
 */

#ifndef BREAKOUTLITE_BRICK_H
#define BREAKOUTLITE_BRICK_H
#include "Painter.h"
#include "Force.h"
#include "Ball.h"
extern int score;
extern bool  deepState;;
class Brick {
public:
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Este es el constructor de cada bloque del juego, este contiene el tipo de bloque, su posicion de fila
     * y columna
     * @param col Posicion de Columna
     * @param row Posicion de Fila
     * @param type Tipo de bloque
     */
    Brick(int col, int row, int type);
    enum { WIDTH = 25,
        HEIGHT = 20 };
    /**
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     * @brief Metodo el cual se encarga de dibujar los bloques en pantalla
     * @param Painter
     */
    void draw(Painter &) const;
    /**
    * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
    * @brief Metodo el cual se encarga de revisar si un bloque tiene los suficientes golpes necesarios para ser
     * destruido
    */
    void destroy();
    /**
    * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
    * @brief Metodo el cual se encarga de chequear las colisiones que suceden entre la bola y los bloques, ademas si una bola
     * toca a un blque este metodo se encarga de calcular la fuerza resultante de rebote
    * @param Ball
    */
    Force tick(const Ball &);
    int points;
    bool destroyed= false;
private:
    int hits;
    int type;
    float col_;
    float row_;
    /**
     * @public
     * @param t
     * @brief Metodo que establece que tipo de bloque es mediante un int y ademas establece los parametros
     * points y hits.
     */
    void setType(int t);
    /**
     * @public
     * @brief Metodo que verifica que tipo de bloque es y decide si el bloque tiene suficientes hits como para destruirse
     */
    void checkDestroyed();
    int countDownTimer_;
};


#endif //BREAKOUTLITE_BRICK_H
