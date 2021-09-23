#include <string>
#include "Datagrama.h"
#include <iostream>

using namespace std;

Datagrama::Datagrama(int origem, int destino, string dado) :
    origem(origem), destino(destino), dado(dado){}

Datagrama::~Datagrama()
{
    //dtor
}

int Datagrama::getOrigem() {
    return origem;
}

int Datagrama::getDestino() {
    return destino;
}

string Datagrama::getDado() {
    return dado;
}

void Datagrama::imprimir(){
    cout << "Origem: " << getOrigem() << endl;
    cout << "Destino: " << getDestino() << endl;
    cout << "Dado: " << getDado() << endl;
}
