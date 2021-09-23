#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho) {
    posicaoVazia = 0;
    roteadorPadrao = NULL;
    atrasoPadrao = 0;
}

TabelaDeRepasse::~TabelaDeRepasse()
{
    //dtor
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente, int atraso) {
    for (int i = 0; i < posicaoVazia; i++) {
        if (enderecosDeDestino[i] == endereco)
            return false;
    }
    if (posicaoVazia < tamanho) {
        enderecosDeDestino[posicaoVazia] = endereco;
        roteadoresAdjacentes[posicaoVazia] = adjacente;
        atrasos[posicaoVazia] = atraso;
        posicaoVazia++;
        return true;
    }
    else
        return false;
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    return roteadoresAdjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return posicaoVazia;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao, int atraso) {
    roteadorPadrao = padrao;
    atrasoPadrao = atraso;
}

Roteador* TabelaDeRepasse::getProximoSalto(int endereco, int& atraso) {
    for (int i = 0; i < posicaoVazia; i++) {
        if (enderecosDeDestino[i] == endereco){
            atraso = atrasos[i];
            return roteadoresAdjacentes[i];
        }
    }
    atraso = atrasoPadrao;
    return roteadorPadrao;

}

void TabelaDeRepasse::imprimir()
{

}

