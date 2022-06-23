#ifndef OPERADOR_H
#define OPERADOR_H
#include <iostream>
#include "Funcionarios.h"


class Operador: public Funcionarios{
public:
    //construtores
    Operador();
    Operador(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario);

    //metodos virutal puro herdados da class funcionario
    void LerAtributos(int numFuncionario);
    void exibirAtributos();
    void aumentoSalario();

    //metodos virtual herdados da class funcionario 
    string getAreaDeFormacao();
    string getAreaSupervisao();
    string getFormacaoAcademicaMaxima();
    void setAreaSupervisao(string areaSupervisao);
    void setAreaDeFormacao(string areaDeFormacao);
    void setFormacaoAcademicaMaxima(string FormacaoAcademicaMaxima);

private:

};

#endif