#ifndef DIRETOR_H
#define DIRETOR_H
#include "Funcionarios.h"

class Diretor : public Funcionarios
{

public:
    //Construtores
    Diretor();
    Diretor(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string AreaDeSupervisao, string areaDeFormacao);
    Diretor(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario);

    //Metodos virutais da classe Funcionarios
    void LerAtributos(int numFuncionario);
    void exibirAtributos();
    void aumentoSalario();

    //Metodos especificos da classe Diretor
    string getAreaDeSupervisao();
    void setAreaDeSupervisao(string areaDeSupervisao);
    string getAreaDeFormacao();
    void setAreaDeFormacao(string areaDeFormacao);

    string getFormacaoAcademicaMaxima();
    void setFormacaoAcademicaMaxima(string FormacaoAcademicaMaxima);

private:
    //Atributos especificos da classe Diretor
    string areaDeSupervisao;
    string areaDeFormacao;

};

#endif