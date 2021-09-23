#include "Roteador.h"


Roteador::Roteador(int endereco) : endereco(endereco) {
    tabelaHash = new TabelaDeRepasse(TAMANHO);
    filaDeEventos = new Fila(TAMANHO);
}

Roteador::~Roteador() {
    delete tabelaHash;
    delete filaDeEventos;
}

bool Roteador::mapear(int endereco, Roteador* adjacente, int atraso)
{

}

void Roteador::setPadrao(Roteador* padrao, int atraso)
{

}

int Roteador::getEndereco() {
    return endereco;
}

void Roteador::receber(Datagrama* d)
{

}

Evento* Roteador::processar(int instante)
{

}

void Roteador::imprimir()
{

}

