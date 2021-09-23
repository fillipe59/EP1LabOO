#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H
#include "Roteador.h"
#include <iostream>

using namespace std;

class Roteador;

class TabelaDeRepasse
{
    public:
        TabelaDeRepasse(int tamanho);
        ~TabelaDeRepasse();

        bool mapear(int endereco, Roteador* adjacente, int atraso);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();

        void setPadrao(Roteador* padrao, int atraso);

        Roteador* getProximoSalto(int endereco, int& atraso);

        void imprimir();

    private:
        int tamanho;
        Roteador* roteadorPadrao;
        int atrasoPadrao;
        int* enderecosDeDestino;
        Roteador** roteadoresAdjacentes;
        int* atrasos;
        int posicaoVazia;
};

#endif // TABELADEREPASSE_H

