#include <string>
#include <iostream>

using namespace std;

#include "Fila.h"
#include "Datagrama.h"


Fila::Fila(int tamanho) : tamanho(tamanho) {
    inicio = 0;
    fim = 0;
    contador = 0;
    vetorDatagramas = new Datagrama*[tamanho];
}

Fila::~Fila() {
    if (inicio < fim) {
        for (int i = inicio; i < fim; i++)
            delete vetorDatagramas[i];//varre do incio ao fim da fila
    }
    else {
        for (int i = inicio; i < tamanho; i++)
            delete vetorDatagramas[i]; //varre do inicio da fila ao fim do vetor
        for (int i = 0; i < fim; i++)
            delete vetorDatagramas[i];

    delete[] vetorDatagramas;

}

bool Fila::enqueue(Datagrama* d) {
    if (tamanho == contador)
        return false;
    else {
        vetorDatagramas[fim] = d;

        if (fim  == tamanho - 1)
            fim = 0; //garante que a fila eh circular
        else
            fim += 1;

        contador += 1;
        return true;
    }
}

Datagrama* Fila::dequeue() {
    if (isEmpty() == true)
        return NULL;

    else {
        int aux = inicio;
        contador -= 1;
        if (inicio == tamanho - 1)
            inicio = 0;
        else
            inicio += 1;

        return vetorDatagramas[aux];
    }
}

bool Fila::isEmpty() {
    return contador == 0;
}

int Fila::getSize() {
    return contador;
}

void Fila::imprimir() {
    if (isEmpty() == true)
        cout << "Fila vazia" << endl;
    else {
        if (inicio < fim) {
                for (int i = inicio; i % tamanho < fim; i++)
                    vetorDatagramas[i]->imprimir();//varre do incio ao fim da fila
        }
        else {
            for (int i = inicio; i < tamanho; i++)
                vetorDatagramas[i]->imprimir(); //varre do inicio da fila ao fim do vetor
            for (int i = 0; i < fim; i++)
                vetorDatagramas[i]->imprimir(); //varre do inicio do vetor ao fim da fila
        }
    }
}

