#include "Gerente.h"

Gerente::Gerente(){
 
}

Gerente::Gerente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string getAreaDeSupervisao)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
    this->areaDeSupervisao = getAreaDeSupervisao;
}

Gerente::Gerente(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this ->salario = salario;
}

string Gerente::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}

void Gerente::setAreaDeSupervisao(string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}

//metodo para ler os atributos da classe gerente
void Gerente::LerAtributos(int numFuncionario)
{

    cout << "Digite a area de supervisao: ";
    getline(cin, areaDeSupervisao);
    system("clear||cls");
}   

//metodo para exibir os atributos da classe gerente
void Gerente::exibirAtributos()
{
    cout << "Numero do funcionario: " << numeroDoFuncionario << endl;
    cout << "Nome do funcionario: " << nome << endl;
    getEndereco().exibirEnderecoCompleto();
    cout << "Telefone do funcionario: " << telefone << endl;

    cout << "Data de contratacao do funcionario: ";
    getDataDeIngresso().exibirData();

    cout << "Designacao do funcionario: " << designacao << endl;
    cout << "Salario do funcionario: " << salario << endl;
    cout << "Area de supervisao: " << areaDeSupervisao << endl;
}

//metodo aumento salario
void Gerente::aumentoSalario()
{
    this->salario += (salario * 0.1);
}

string Gerente::getAreaDeFormacao()
{
    return NULL;
}

string Gerente::getFormacaoAcademicaMaxima()
{
    return NULL;
}

void Gerente::setAreaDeFormacao(string areaDeFormacao){
}

void Gerente::setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima){
}