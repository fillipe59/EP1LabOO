#include "Roteador.h"


Roteador::Roteador(int endereco) : endereco(endereco) {
    tabelaDoRoteador = new TabelaDeRepasse(TAMANHO);
    filaDeDatagramas = new Fila(TAMANHO);
}

Roteador::~Roteador() {
    delete tabelaDoRoteador;
    delete filaDeDatagramas;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso) {
    return tabelaDoRoteador->mapear(endereco, adjacente, atraso);
}

void Roteador::setPadrao(Roteador* padrao, int atraso) {
    tabelaDoRoteador->setPadrao(padrao, atraso);
}

int Roteador::getEndereco() {
    return endereco;
}

void Roteador::receber(Datagrama* d) {
    if (filaDeDatagramas->enqueue(d) == false) {
        cout << "\tFila em " << endereco <<  "estourou" << endl;
    }
}

Evento* Roteador::processar(int instante) {
    if (filaDeDatagramas->isEmpty() == true)
        return NULL;
    else {
        cout << "Roteador " << endereco << endl;
        Datagrama* dtRetirado = filaDeDatagramas->dequeue();
        if (dtRetirado->getDestino() == endereco) {
            cout << "\tRecebido: " << dtRetirado->getDado() << endl;
            delete dtRetirado;
            return NULL;
        }

        else {
            int atraso;
            Roteador* proximoRoteador = tabelaDoRoteador->getProximoSalto(dtRetirado->getDestino(), atraso);
            if (proximoRoteador == NULL) {
                cout << "\tSem proximo: " << "Origem: " << dtRetirado->getOrigem() << ", Destino: " << dtRetirado->getDestino() << ", "<< dtRetirado->getDado() << endl;
                delete dtRetirado;
                return NULL;
            }
            else {
                cout << "\tRepassado para " << proximoRoteador->getEndereco() << " (instante " << instante + atraso << "): ";
                cout << "Origem: " << dtRetirado->getOrigem() << " Destino: " << dtRetirado->getDestino() << ", " << dtRetirado->getDado() << endl;
                Evento* evento = new Evento(instante + atraso, proximoRoteador, dtRetirado);
                return evento;
            }
        }
    }
}

void Roteador::imprimir()
{

}

