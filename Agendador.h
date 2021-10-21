#ifndef AGENDADOR_H
#define AGENDADOR_H
#include "Rede.h"
#include "Datagrama.h"
#include "Evento.h"
#include "Roteador.h"
#include <iostream>

using namespace std;

class Agendador
{
    public:
        Agendador(int instanteInicial, Rede* rede, int tamanho);
        ~Agendador();

        bool agendar(int instante, Roteador* r, Datagrama* d);
        void processar();
        int getInstante();

        void imprimirEventos();

    private:
        Rede* rede;
        int tamanho;
        Evento** eventosAgendados;
        int quantidade;
        int instanteAtual;
};

#endif // AGENDADOR_H

