#include "Diretor.h"

Diretor::Diretor()
{

}

//construtor da classe Diretor para criar quando ler do arquivo
Diretor::Diretor(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario, string AreaDeSupervisao, string areaDeFormacao){
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
    this->areaDeSupervisao = AreaDeSupervisao;
    this->areaDeFormacao = areaDeFormacao;
}

//construtor da classe Diretor para criar quando adicionado do menu
Diretor::Diretor(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario){
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
}

//metodo para ler os atributos do diretor
void Diretor::LerAtributos(int numFuncionario){

    cout << "Digite a area de supervisao: ";
    getline(cin, areaDeSupervisao);
    system("clear||cls");

    cout << "Digite a area de formacao: ";
    getline(cin, areaDeFormacao);
    system("clear||cls");
}

//metodo para exibir os atributos
void Diretor::exibirAtributos(){

    cout << "Numero do funcionario: " << numeroDoFuncionario << endl;
    cout << "Nome do funcionario: " << nome << endl;
    getEndereco().exibirEnderecoCompleto();
    
    cout << "Telefone do funcionario: " << telefone << endl;

    cout << "Data de contratacao do funcionario: ";
    getDataDeIngresso().exibirData();

    cout << "Designacao do funcionario: " << designacao << endl;
    cout << "Salario do funcionario: " << salario << endl;
    cout << "Area de supervisao: " << areaDeSupervisao << endl;
    cout << "Area de formacao academica: " << areaDeFormacao << endl;

}

//metodo para aumento de salario
void Diretor::aumentoSalario(){
    this->salario += (salario * 0.2);
}

//metodo da classe Diretor
string Diretor::getAreaDeSupervisao()
{
    return areaDeSupervisao;
}

string Diretor::getAreaDeFormacao()
{
    return areaDeFormacao;
}

void Diretor::setAreaDeSupervisao(string areaDeSupervisao)
{
    this->areaDeSupervisao = areaDeSupervisao;
}

void Diretor::setAreaDeFormacao(string areaDeFormacao)
{
    this->areaDeFormacao = areaDeFormacao;
}

string Diretor::getFormacaoAcademicaMaxima()
{
    return NULL;
}

void Diretor::setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima){
}