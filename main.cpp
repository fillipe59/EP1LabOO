#include "Agendador.h"
#include "Datagrama.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Rede *rede = new Rede (6);
    Agendador *agendador = new Agendador(1, rede, 10);

    Roteador *r1 = new Roteador(1);
    Roteador *r2 = new Roteador(2);
    Roteador *r3 = new Roteador(3);
    Roteador *r4 = new Roteador(4);
    Roteador *r5 = new Roteador(5);
    Roteador *r6 = new Roteador(6);

    rede->adicionar(r1);
    rede->adicionar(r2);
    rede->adicionar(r3);
    rede->adicionar(r4);
    rede->adicionar(r5);
    rede->adicionar(r6);

    r1->setPadrao(r3, 1);
    r2->setPadrao(r4, 1);
    r3->setPadrao(r4, 1);
    r4->setPadrao(r3, 1);
    r5->setPadrao(r3, 2);
    r6->setPadrao(r4, 1);

    r1->mapear(2,r2,2);
    r2->mapear(1,r1,2);
    r3->mapear(1,r1,1);
    r3->mapear(5,r5,2);
    r4->mapear(2,r2,1);
    r4->mapear(6,r6,1);
    r5->mapear(6,r6,2);
    r6->mapear(5,r5,2);

    int enderecoOrigem;
    int instante;
    int enderecoDestino;
    string mensagem;

    int qtdDeTempo;

    int comando = 4;

    while (comando != 0) {

        cout<< "Simulador de Rede" << endl;
        cout<< "1) Enviar um datagrama" << endl;
        cout<< "2) Passar tempo" << endl;
        cout<< "0) Sair" << endl;
        cout<< "Escolha uma opcao: ";

        cin >> comando;
        cout << endl;

        if (comando == 1) {
            cout << "Endereco do roteador de origem: ";
            cin >>  enderecoOrigem;

            cout << "Instante: ";
            cin >>  instante;

            cout << "Endereco de destino: ";
            cin >>  enderecoDestino;

            cout << "Mensagem: ";
            cin >>  mensagem;
            cout << endl;

            if (enderecoOrigem < 0 || enderecoOrigem > 6) {
                cout <<  "Erro: origem desconhecida" << endl;
                cout << endl;
            }
            else if (!agendador->agendar(instante, rede->getRoteador(enderecoOrigem), new Datagrama(enderecoOrigem, enderecoDestino, mensagem))) {
                cout << "Erro: Sem espaco para agendar o evento" <<  endl;
                cout << endl;
            }
        }

        if (comando == 2) {
            cout << "Quantidade de tempo: ";
            cin >> qtdDeTempo;
            cout << endl;

            for (int tempo = 1; tempo <= qtdDeTempo; tempo++){
                cout << "Instante " << agendador->getInstante() << endl;
                cout  << "---"<< endl;
                agendador->processar();
                cout << endl;
            }
        }
    }

    delete rede;
    delete agendador;

    return 0;
}
