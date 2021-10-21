#include "Agendador.h"

Agendador::Agendador(int instanteInicial, Rede* rede, int tamanho) :
instanteAtual(instanteInicial), rede(rede), tamanho(tamanho) {
    eventosAgendados = new Evento*[tamanho];
    quantidade = 0;
}

Agendador::~Agendador() {
    for (int i = 0; i < quantidade; i++)
        delete eventosAgendados[i];
    delete[] eventosAgendados;
}

bool Agendador::agendar(int instante, Roteador* r, Datagrama* d) {
    if (quantidade >= tamanho){
        cout << "overflow";
        return false;
    }

    else {
        eventosAgendados[quantidade] = new Evento(instante, r, d);
        quantidade++;
        return true;
    }
}

void Agendador::imprimirEventos(){
    for (int i = 0; i < quantidade; i++){
        cout <<  "evento de numero:"<< i << endl;
        eventosAgendados[i]->imprimir();
    }
}

void Agendador::processar(){
    /*
    cout << "antes do instante" << instanteAtual <<endl;
    for (int i = 0; i < quantidade; i++){
    cout <<  "evento de numero:"<< i << endl;
    eventosAgendados[i]->imprimir();
    }
    */

    for (int i = 0; i < quantidade ; i++) {
        if (instanteAtual == eventosAgendados[i]->getInstante()) {
            eventosAgendados[i]->getDestino()->receber(eventosAgendados[i]->getDatagrama());

            for (int u = i; u < quantidade - 1; u++){
                eventosAgendados[u] = eventosAgendados[u+1];
            }
            i--;

            quantidade--;
        }
    }

    /*
    cout << "enviados para os roteadores no instan" << instanteAtual <<endl;
    for (int i = 0; i < quantidade; i++){
    cout <<  "evento de numero:"<< i << endl;
    eventosAgendados[i]->imprimir();
    }
    */

    Evento *nullOuEvento = NULL;
    for (int i = 0; i < rede->getQuantidade(); i++){
        nullOuEvento = rede->getRoteadores()[i]->processar(instanteAtual);
        if (nullOuEvento != NULL){
            agendar(nullOuEvento->getInstante(), nullOuEvento->getDestino(), nullOuEvento->getDatagrama());
        }
    }
    instanteAtual++;
}

int Agendador::getInstante() {
    return instanteAtual;
}

