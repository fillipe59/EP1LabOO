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
    if (quantidade >= tamanho)
        return false;
    else {
        eventosAgendados[quantidade] = new Evento(instante, r, d);
        quantidade++;
        return true;
    }
}

void Agendador::processar(){
    int posicoesDeletadas[quantidade];

    int eventosApagados = 0;
    for (int i = 0; i < quantidade ; i++) {
        if (instanteAtual == eventosAgendados[i]->getInstante()) {
            eventosAgendados[i]->getDestino()->receber(eventosAgendados[i]->getDatagrama());
            delete eventosAgendados[i];

            posicoesDeletadas[eventosApagados] = i;
            eventosApagados ++;
        }
    }
    quantidade = quantidade - eventosApagados;

    for (int i = 0; i < eventosApagados; i++){
        for (int u = posicoesDeletadas[i]; u < quantidade + eventosApagados; u++)
            if (u+1 < tamanho)
                eventosAgendados[u] = eventosAgendados[u+1];
    }

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

