/**
 * @file Ball.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase del SocketClient
 * @brief Contiene las funcionalidades del Cliente
 * @date 30/9/2021
 */
#ifndef CLIENT_SOCKETCLIENT_H
#define CLIENT_SOCKETCLIENT_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;
class SocketClient {
public:
    SocketClient();
    /**
     * @brief Crear la conexion al Servidor ademas contiene el descriptor y el Inet address
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    void connect_client();
    /**
     * @brief Metodo que mando los mensajes del Cliente al Servidor
     * @param msn
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    void send_message(const char* msn) const;

private:
    int descriptor;
    sockaddr_in info;
    /**
     * @public
     * @brief Metodo que el controlador del Cliente
     * @param obj
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    static void* controller(void* obj);
};


#endif //CLIENT_SOCKETCLIENT_H
