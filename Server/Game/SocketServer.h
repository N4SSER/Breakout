/**
 * @file SocketServer.h
 * @version 1.0
 * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
 * @title Clase del Server
 * @brief Contiene las funciones del servidor.
 * @date 30/9/2021
 */
#ifndef SERVER_SOCKETSERVER_H
#define SERVER_SOCKETSERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>

using namespace std;
struct dataSocket{
    int descriptor;
    sockaddr_in info;
};
class SocketServer {
public:
    SocketServer();
    /**
     * @brief Primero espera a que se conecte un cliente, luego cuando se conecta un cliente este cliente es almacenado
     * en un vector de clientes, ademas crea los hilos de los clientes
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    void run();
    void send_message(const char* msn);

private:
    /**
     * @public
     * @param msg Mesaje enviado por el cliente
     * @brief Recibe los mensaje enviados por el cliente, luego este los interpreta si son la tecla indicada para convetir esta
     * tecla a un evento en el juego
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    static void ctrlC(string msg);
    int descriptor{};
    sockaddr_in info{};
    vector<int> clients;
    /**
     * @public
     * @brief Crea el socket
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    bool create_socket();
    /**
     * @public
     * @brief Crea el link al kernel
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    bool link_kernel();
    /**
     * @public
     * @brief Metodo que controlo los mensajes del cliente, ademas lee e interpreta estos mensajes mandados por el cliente
     * @authors Brown Aparicio Nasser Santiago, Ramos Madrigal Jose Pablo
     */
    static void* client_controller(void* obj);
};


#endif //SERVER_SOCKETSERVER_H
