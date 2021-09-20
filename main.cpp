#include "Datagrama.h"
#include "Fila.h"
#include <string>
#include <iostream>

using namespace std;

void testeDatagrama() {
    Datagrama *dg1 = new Datagrama(0, 2, "Oi");
    dg1->imprimir();
    dg1->~Datagrama();
};

void testeFila() {
    Datagrama *dg1 = new Datagrama(1, 101, "dg1");
    Datagrama *dg2 = new Datagrama(2, 102, "dg2");
    Datagrama *dg3 = new Datagrama(3, 103, "dg3");
    Datagrama *dg4 = new Datagrama(4, 104, "dg4");

    Fila *f1 = new Fila(3);
    f1->enqueue(dg1);
    f1->enqueue(dg2);
    f1->enqueue(dg3);
    f1->enqueue(dg4);
    f1->dequeue();
    f1->dequeue();
    f1->enqueue(dg4);
    f1->dequeue();
    f1->enqueue(dg2);
    f1->imprimir();
};

int main() {
    //testeDatagrama();
    testeFila();
    return 0;
}
