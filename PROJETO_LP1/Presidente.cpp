#include "Presidente.h"

Presidente::Presidente()
{

}

Presidente::Presidente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string areaDeFormacao, string formacaoAcademicaMaxima)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
    this->areaDeFormacao = areaDeFormacao;
    this->formacaoAcademicaMaxima = formacaoAcademicaMaxima;
}

Presidente::Presidente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario){
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
}

//metodo para ler os atributos do funcionario
void Presidente::LerAtributos(int numFuncionario){

    cout << "Digite a area de formacao: " << endl;
    getline(cin, areaDeFormacao);
    system("clear||cls");

    cout << "Digite a formacao academica: " << endl;
    getline(cin, formacaoAcademicaMaxima);
    system("clear||cls");

}

//metodo para exibir os atributos
void Presidente::exibirAtributos(){

    cout << "Numero do funcionario: " << numeroDoFuncionario << endl;
    cout << "Nome do funcionario: " << nome << endl;
    getEndereco().exibirEnderecoCompleto();
    cout << "Telefone do funcionario: " << telefone << endl;

    cout << "Data de contratacao do funcionario: ";
    getDataDeIngresso().exibirData();

    cout << "Designacao do funcionario: " << designacao << endl;
    cout << "Salario do funcionario: " << salario << endl;
    cout << "Area de formacao academica: " << areaDeFormacao << endl;
    cout << "Nivel de formacao academica: " << formacaoAcademicaMaxima << endl;
}

//metodo para aumentar o salario
void Presidente::aumentoSalario(){
    this->salario += (salario * 0.3);
}

string Presidente::getAreaDeFormacao()
{
    return areaDeFormacao;
}

void Presidente::setAreaDeFormacao(string areaDeFormacao)
{
    this->areaDeFormacao = areaDeFormacao;
}

string Presidente::getFormacaoAcademicaMaxima()
{
    return formacaoAcademicaMaxima;
}

void Presidente::setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima)
{
    this->formacaoAcademicaMaxima = formacaoAcademicaMaxima;
}

string Presidente::getAreaSupervisao()
{
    return NULL;
}

void Presidente::setAreaSupervisao(string areaSupervisao){
}