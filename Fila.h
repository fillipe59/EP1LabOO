#include "Datagrama.h"
#include <string>
#include <iostream>

using namespace std;

#ifndef FILA_H
#define FILA_H


class Fila
{
    public:
        Fila(int tamanho);
        ~Fila();

        bool enqueue(Datagrama* d); //adiciona um datagram a o fim da fila
        Datagrama* dequeue(); //retira um datagrma do inicio da fila
        bool isEmpty(); //indica se a fila esta vazia
        int getSize(); //retorna o tamanho da fila

        void imprimir(); //imprime os datagramas da fila em ordem

    private:
        int tamanho; //tamanho do vetor de dtagramas
        int inicio; //indica de qual posicao sera retirado o proximo datagrama
        int fim; //indica em q posicao o proximo datagrama sera adicionado
        int contador; //tamanho da fila
        Datagrama **vetorDatagramas; //vetor
};

#endif // FILA_H

