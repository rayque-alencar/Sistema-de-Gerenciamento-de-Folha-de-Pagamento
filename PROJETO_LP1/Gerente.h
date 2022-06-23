#ifndef GERENTE_H
#define GERENTE_H
#include "Funcionarios.h"

class Gerente : public Funcionarios
{

public:
    Gerente();

    //construtor da classe Gerente para criar quando ler do arquivo
    Gerente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string getAreaDeSupervisao);
    
    //constructor da classe Gerente para quando criar funcionario manualmente
    Gerente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario);

    //metodos virutal puro herdados da class funcionario
    void LerAtributos(int numFuncionario);
    
    void exibirAtributos();
    void aumentoSalario();

    //metodos para o atributo da class gerente
    string getAreaDeSupervisao();
    void setAreaDeSupervisao(string areaDeSupervisao);
    
    //metodos herdados da class funcionario
    string getAreaDeFormacao();
    string getFormacaoAcademicaMaxima();
    void setAreaDeFormacao(string areaDeFormacao);
    void setFormacaoAcademicaMaxima(string FormacaoAcademicaMaxima);
    
private:

    //atributos da classe Gerente
    string areaDeSupervisao;

};

#endif