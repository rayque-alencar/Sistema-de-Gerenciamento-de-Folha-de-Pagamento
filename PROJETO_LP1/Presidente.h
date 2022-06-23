#ifndef PRESIDENTE_H
#define PRESIDENTE_H
#include "Funcionarios.h"

class Presidente : public Funcionarios
{
public:
    //Construtores
    Presidente();
    Presidente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string areaDeFormacao, string formacaoAcademicaMaxima);
    Presidente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario);

    //Metodos virutais da classe Funcionarios
    void LerAtributos(int numFuncionario);
    void exibirAtributos();
    void aumentoSalario();

    //Metodos especificos da classe Presidente
    string getAreaDeFormacao();
    void setAreaDeFormacao(string areaDeFormacao);
    string getFormacaoAcademicaMaxima();
    void setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima);

    string getAreaSupervisao();
    void setAreaSupervisao(string areaSupervisao);
    
      
private:
    //Atributos especificos da classe Presidente
    string areaDeFormacao;
    string formacaoAcademicaMaxima;

};

#endif