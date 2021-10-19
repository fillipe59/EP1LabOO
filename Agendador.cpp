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
    if (quantidade == tamanho)
        return false;
    else {
        eventosAgendados[quantidade] = new Evento(instante, r, d);

        return true;
    }
}

void Agendador::processar(){
    for (int i = quantidade - 1; i >= 0 ; i--) {
        if (instanteAtual == eventosAgendados[i]->getInstante()) {
            eventosAgendados[i]->getDestino()->receber(eventosAgendados[i]->getDatagrama());
            delete eventosAgendados[i];
            quantidade --;
        }
    }



    Evento *nullOuEvento = NULL;
    for (int i = 0; i < rede->getQuantidade(); i++){
        nullOuEvento = rede->getRoteadores()[i]->processar(instanteAtual);
        if (nullOuEvento != NULL){
            eventosAgendados[quantidade] = nullOuEvento;
            quantidade++;
        }
    }
    instanteAtual++;


}

int Agendador::getInstante() {
    return instanteAtual;
}

