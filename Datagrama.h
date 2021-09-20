#include <string>
#include <iostream>

using namespace std;

#ifndef DATAGRAMA_H
#define DATAGRAMA_H


class Datagrama
{
    public:
        Datagrama(int origem, int destino, string dado);
        ~Datagrama(); //virtual foi retirado

        int getOrigem(); //retorna origem do datagrama
        int getDestino(); //retorna destino do datagrama
        string getDado(); //retorna dado do datagrama

        void imprimir(); //imprime todos os atributos

    private:
        int origem;
        int destino;
        string dado;
};

#endif // DATAGRAMA_H
