#ifndef FOLHASALARIAL_H
#define FOLHASALARIAL_H

#include <iostream>
#include <ctime>

using namespace std;

class FolhaSalarial
{
public:

    //Construtore
    FolhaSalarial();

    //Metodos
    void calcularINSS(float salario);
    void calcularIRRF(float salario);
    void calcularSalarioLiquido(float salario);
    void calcularSalarioMensal(float salario);

    //lista de metodos set
    void setDiasTrabalhados(float diasTrabalhados);
    void setHorasExtras(float horasExtras);

    //lista de metodos get
    float getsalario();
    float getINSS();
    float getIRRF();
    float getSalarioLiquido();
    float getSalarioMesBrutoComHorasExtras();
    float getSalarioExtra();
    float getDiasTrabalhados();
    float getHorasExtras();

private:
    //atributos
    float salario, salarioLiquido , INSS , IRRF, salarioMesBrutoComHorasExtras, salarioExtra;
    float horasExtras, diasTrabalhados;
    
};
#endif