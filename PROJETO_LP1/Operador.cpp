#include "Operador.h"

Operador::Operador()
{
    
}

Operador::Operador(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso,string designacao, float salario)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this ->salario = salario;
}

//aumentoSalarial, exibirAtributos, LerAtributos sao os metodos virtual puros da class funcionarios e sao implementados na classe Operador
//metodo para ler atributos da classe Operador
void Operador::LerAtributos(int numFuncionario){
    
    this->numeroDoFuncionario = numFuncionario;

}

//metodo para exibir todos os atributos de Operador
void Operador::exibirAtributos(){
    
    cout << "Numero do funcionario: " << numeroDoFuncionario << endl;
    cout << "Nome do funcionario: " << nome << endl;
    getEndereco().exibirEnderecoCompleto();
    
    cout << "Telefone do funcionario: " << telefone << endl;
    cout << "Data de contratacao do funcionario: ";
    getDataDeIngresso().exibirData();

    cout << "Designacao do funcionario: " << designacao << endl;
    cout << "Salario do funcionario: " << salario << endl;

}

//porcentagem de aumento de salario de um funcionario do tipo operador
void Operador::aumentoSalario()
{
    this->salario += (salario * 0.05);    
}

//metodos virtual da class funcionario
string Operador::getAreaDeFormacao()
{
    return NULL;
}

string Operador::getAreaSupervisao()
{
    return NULL;
}

string Operador::getFormacaoAcademicaMaxima()
{
    return NULL;
}

void Operador::setAreaSupervisao(string areaSupervisao){
}

void Operador::setAreaDeFormacao(string areaDeFormacao){
}

void Operador::setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima){
}