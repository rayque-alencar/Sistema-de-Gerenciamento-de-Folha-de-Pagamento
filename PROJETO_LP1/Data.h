#ifndef DATA_H
#define DATA_H
#include <iostream>

using namespace std;

class Data
{
public:

    //Construtores
    Data();
    Data(int dia, int mes, int ano);

    //Metodos set
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);

    //Metodos get
    int getDia();
    int getMes();
    int getAno();

    //Metodos para exibir a data
    void exibirData();

private:

    int dia;
    int mes;
    int ano;



};

#endif