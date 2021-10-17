#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse(int tamanho) : tamanho(tamanho) {
    posicaoVazia = 0;
    roteadorPadrao = NULL;
    atrasoPadrao = 0;
    enderecosDeDestino = new int [tamanho];
    atrasos = new int [tamanho];
    roteadoresAdjacentes = new Roteador*[tamanho];

}

TabelaDeRepasse::~TabelaDeRepasse()
{
    delete [] enderecosDeDestino;
    delete [] atrasos;
    delete [] roteadoresAdjacentes;
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

void TabelaDeRepasse::imprimir() {
    cout << "Quantidade de Adjacentes: " << posicaoVazia << endl;
    cout << "\n";
    for (int i = 0; i < posicaoVazia; i++) {
        cout << "Posicao: " << i + 1 << endl;
        cout << "   Endereco: " << enderecosDeDestino << endl;
        cout << "   Roteador: " << enderecosDeDestino << endl;
    }
}

