#ifndef REDE_H
#define REDE_H
#include "Roteador.h"
#include <iostream>

using namespace std;

class Rede
{
    public:
        Rede(int tamanho);
        ~Rede();

        bool adicionar(Roteador* r);
        Roteador* getRoteador(int endereco);

        Roteador** getRoteadores();
        int getQuantidade();

        void imprimir();
    private:
        int tamanho;
        int quantidade;
        Roteador **roteadores;
};

#endif // REDE_H

