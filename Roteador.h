#ifndef ROTEADOR_H
#define ROTEADOR_H
#define TAMANHO 10
#include "Fila.h"
#include "Datagrama.h"
#include "Evento.h"
#include "TabelaDeRepasse.h"
#include <iostream>

using namespace std;

class Evento;
class TabelaDeRepasse;

class Roteador {
    public:
        Roteador(int endereco);
        ~Roteador();

        bool mapear(int endereco, Roteador* adjacente, int atraso);
        void setPadrao(Roteador* padrao, int atraso);

        int getEndereco();
        void receber(Datagrama* d);
        Evento* processar(int instante);

        void imprimir();

    private:
        int endereco;
        TabelaDeRepasse* tabelaHash;
        Fila* filaDeEventos;
};

#endif // ROTEADOR_H

