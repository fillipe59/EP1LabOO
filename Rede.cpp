#include "Rede.h"

Rede::Rede(int tamanho) : tamanho(tamanho) {
    quantidade = 0;
    roteadores = new Roteador*[tamanho];
}

Rede::~Rede() {
    for (int i =0; i < quantidade; i++)
        delete roteadores[i];
    delete[] roteadores;
}

bool Rede::adicionar(Roteador* r) {
    for (int i = 0; i < quantidade; i++) {
        if (roteadores[i]->getEndereco() == r->getEndereco())
            return false;
    }
    if (quantidade < tamanho) {
        roteadores[quantidade] = r;
        quantidade++;
        return true;
    }
    else
        return false;
}

Roteador* Rede::getRoteador(int endereco) {
    for (int i = 0; i < quantidade; i++) {
        if (roteadores[i]->getEndereco() == endereco)
            return roteadores[i];
    }
    return NULL;
}

Roteador** Rede::getRoteadores() {
    return roteadores;
}

int Rede::getQuantidade() {
    return quantidade;
}

void Rede::imprimir() {

}

