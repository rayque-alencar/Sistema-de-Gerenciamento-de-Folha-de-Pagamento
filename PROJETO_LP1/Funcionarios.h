#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "FolhaSalarial.h"
#include "Endereco.h"
#include "Data.h"

using namespace std;

class Funcionarios : public Data{
    
public:
    //construtores
    Funcionarios();
    Funcionarios(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario);

    //metodos get
    int getNumeroDoFuncionario();
    string getNome();
    Endereco getEndereco();
    string getTelefone();
    Data getDataDeIngresso();
    string getDesignacao();
    float getSalario();
    FolhaSalarial getFolhaSalarial(int mes);

    //metodos set
    void setNumeroDoFuncionario(int);
    void setNome(string);
    void setEndereco(string cep, string numero);
    void setTelefone(string);
    void setDataDeIngresso(Data);
    void setDesignacao(string);
    void setSalario(float);

    //metodos
    void calcularFolhaSalarial();
    void setDiasTrabalhados(int diasTrabalhados, int mes);
    void setHorasExtras(int horasExtra, int mes);
    void calculaFolhaMensal(float Salario, int mes);
    void imprimirFolhaSalarial(int mes);

    //metodos para usar folha salarial
    void exibirFolhaAnual();
    void exibirFolhaMes(int mes);
    float getSalarioAnual();

    //metodos virtual puro
    virtual void LerAtributos(int numFuncionario) = 0;
    virtual void exibirAtributos() = 0;
    virtual void aumentoSalario() = 0;

    //metodos virtual 
    virtual string getAreaDeFormacao();
    virtual string getAreaSupervisao();
    virtual string getFormacaoAcademicaMaxima();  
    virtual void setAreaSupervisao(string areaSupervisao);
    virtual void setAreaDeFormacao(string areaDeFormacao);
    virtual void setFormacaoAcademicaMaxima(string FormacaoAcademicaMaxima);


private:

protected:
    //atributos
    int numeroDoFuncionario;
    string nome;
    Endereco endereco;
    string telefone;
    Data dataDeIngresso;
    string designacao;
    float salario;
    FolhaSalarial folhaSalarial[12];

};

#endif