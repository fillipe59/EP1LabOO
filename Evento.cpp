#include "Evento.h"

Evento::Evento(int instante, Roteador* destino, Datagrama* d) :
instante(instante), roteadorDestino(destino), d(d) {}

Evento::~Evento() {
    //dtor
}

int Evento::getInstante() {
    return instante;
}

Roteador* Evento::getDestino() {
    return roteadorDestino;
}

Datagrama* Evento::getDatagrama() {
    return d;
}

void Evento::imprimir()
{
    cout << "Instante: " << instante << endl;
    cout << "Roteador de destino: " << roteadorDestino->getEndereco() << endl;
    cout <<  d->getDado() << endl;

}

