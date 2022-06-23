#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "Funcionarios.h"
#include "Gerente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"

using namespace std;

class Menu
{
public:

    Menu();
    void menuInicial();
    void adicionarFuncionario();
    void exibirFuncionario(int indice);
    void exibirListaDeFuncionarios();
    void procurarFuncionario();
    void editarFuncionario();
    void excluirFuncionario();
    void exibirFuncionariosPorTipo(string tipo);

    void concederAumento();
    void calcularFolhaSalarial();
    void setDiasAleatorios(int mes, int diasAleatorios);
    void setHorasAleatorias(int mes, int horasAleatorias);
    void imprimeFolhaSalarialFuncionario();
    void exibirFolhaDaEmpresa();

    int getFuncionarioPeloNumeroDoFuncionario(int numeroDoFuncionario);
    int getFuncionarioPorNome(string nome);

    void salvarArquivoFuncionario();
    void lerArquivoFuncionario();
    void salvarArquivoFuncionario(int);

private:
    //atributos
    bool folhaSalarialCalculada[12];
    vector<Funcionarios*> vFuncionarios;
    
};

#endif