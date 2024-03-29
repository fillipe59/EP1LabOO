#ifndef EVENTO_H
#define EVENTO_H
#include "Datagrama.h"
#include "Roteador.h"
#include <iostream>

using namespace std;

class Datagrama;
class Roteador;

class Evento
{
    public:
        Evento(int instante, Roteador* destino, Datagrama* d);
        ~Evento();

        int getInstante();
        Roteador* getDestino();
        Datagrama* getDatagrama();

        void imprimir();
    private:
        int instante;
        Roteador* roteadorDestino;
        Datagrama* d;
};

#endif // EVENTO_H

