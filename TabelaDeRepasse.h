/*#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H


class TabelaDeRepasse
{
    public:
        TabelaDeRepasse(int tamanho);
        ~TabelaDeRepasse();

        bool mapear(int endereco, Roteador* adjacente, int atraso);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();

        void setPadrao(Roteador* padrao, int atraso);

        Roteador* getProximoSalto(int endereco, int& atraso);

        void imprimir();

    private:
};

#endif // TABELADEREPASSE_H
*/
