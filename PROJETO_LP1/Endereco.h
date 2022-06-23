#ifndef ENDERECO_H
#define ENDERECO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Endereco
{
public:
    //Construtores
    Endereco();
    Endereco(string cep, string numero);

    //metodo para pegar os dados do endereco com o cep
    void parseCEP();

    //metodos getters
    string getRua();
    string getBairro();
    string getCidade();
    string getEstado();
    string getCep();
    string getNumero();

    //metodos setters
    void setRua(string rua);
    void setBairro(string bairro);
    void setCidade(string cidade);
    void setEstado(string estado);
    void setCep(string cep);
    void setNumero(string numero);

    //metodo para imprimir os dados do endereco
    void exibirEnderecoCompleto();

private:
    //atributos
    string rua, bairro, cidade, estado, cep, numero;

};

#endif