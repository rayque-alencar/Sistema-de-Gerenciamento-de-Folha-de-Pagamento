#include "Funcionarios.h"

Funcionarios::Funcionarios()
{

}

Funcionarios::Funcionarios(int numeroDoFuncionario, string nome, Endereco endereco, string telefone, Data dataDeIngresso, string designacao, float salario)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataDeIngresso = dataDeIngresso;
    this->designacao = designacao;
    this->salario = salario;
}

// lista de setters da class Funcionarios

void Funcionarios::setDataDeIngresso(Data dataDeIngresso)
{
    this-> dataDeIngresso = dataDeIngresso;
}

void Funcionarios::setDesignacao(string designacao)
{
    this->designacao = designacao;
}


void Funcionarios::setNome(string nome)
{
    this->nome = nome;
}

void Funcionarios::setNumeroDoFuncionario(int numeroDoFuncionario)
{
    this->numeroDoFuncionario = numeroDoFuncionario;
}

void Funcionarios::setSalario(float salario)
{
    this->salario = salario;
}

void Funcionarios::setTelefone(string telefone)
{
    this->telefone = telefone;
}

// lista de getters da class Funcionarios

Data Funcionarios::getDataDeIngresso()
{
    return dataDeIngresso;
}

string Funcionarios::getDesignacao()
{
    return designacao;
}

string Funcionarios::getNome()
{
    return nome;
}

string Funcionarios::getTelefone()
{
    return telefone;
}

int Funcionarios::getNumeroDoFuncionario()
{
    return numeroDoFuncionario;
}

float Funcionarios::getSalario()
{
    return salario;
}

//inicio do tratamento da folha salarial
FolhaSalarial Funcionarios::getFolhaSalarial(int mes)
{
    return folhaSalarial[mes - 1];
}

void Funcionarios::setDiasTrabalhados(int diasTrabalhados, int mes)
{
    folhaSalarial[mes - 1].setDiasTrabalhados(diasTrabalhados);
}

void Funcionarios::setHorasExtras(int horasExtra, int mes)
{
    folhaSalarial[mes - 1].setHorasExtras(horasExtra);
}

void Funcionarios::calculaFolhaMensal(float Salario, int mes)
{
    folhaSalarial[mes-1].calcularSalarioMensal(Salario);
    folhaSalarial[mes-1].calcularINSS(Salario);
    folhaSalarial[mes-1].calcularIRRF(Salario);
    folhaSalarial[mes-1].calcularSalarioLiquido(Salario);
}

void Funcionarios::imprimirFolhaSalarial(int mes)
{
    
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Nome do funcionario: " << nome << endl;
    cout << "Salario Liquido: R$ " << folhaSalarial[mes-1].getSalarioLiquido() << endl;
    cout << "Salario Total: R$ " << folhaSalarial[mes-1].getSalarioMesBrutoComHorasExtras() << endl;
    cout << "Valor recebido com as horas extra: R$ " << folhaSalarial[mes-1].getSalarioExtra() << endl;
    cout << "INSS: R$ " << folhaSalarial[mes-1].getINSS() << endl;
    cout << "IRRF: R$ " << folhaSalarial[mes-1].getIRRF() <<endl;
    cout << "Total de Descontos: R$ " << folhaSalarial[mes-1].getINSS() + folhaSalarial[mes-1].getIRRF() << endl;
    cout << "dias trabalhados: " << folhaSalarial[mes-1].getDiasTrabalhados() << endl;
    cout << "horas extras: " << folhaSalarial[mes-1].getHorasExtras() << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << endl;

}

float Funcionarios::getSalarioAnual()
{
    float total = 0;
    
    for(int i = 0; i < 12; i++)
    {
        total += folhaSalarial[i].getsalario();
    }

    return total;
    
}

void Funcionarios::exibirFolhaAnual(){

    cout << "Folha salarial da empresa anual: "<< endl;
    cout << "Total: R$ " << getSalarioAnual() << endl;
    
}

void Funcionarios::exibirFolhaMes(int mes){

    cout << "Folha salarial do mes: " << mes << endl;
    cout << "Salario Bruto: R$ " << folhaSalarial[mes-1].getsalario() << endl;

}

//fim do tratamento da folha salarial

//incio do tratamento do endereco
void Funcionarios::setEndereco(string cep, string numero)
{
    this->endereco = Endereco(cep, numero);
}

Endereco Funcionarios::getEndereco()
{
    return endereco;
}

//fim do tratamento do endereco

//metodo virtual para acessar atributos nas outras class
string Funcionarios::getAreaDeFormacao()
{
    return "nao";
}

string Funcionarios::getAreaSupervisao()
{
    return "nao";
}

string Funcionarios::getFormacaoAcademicaMaxima()
{
    return "nao";
}

void Funcionarios::setAreaSupervisao(string areaSupervisao){
}

void Funcionarios::setAreaDeFormacao(string areaDeFormacao){
}

void Funcionarios::setFormacaoAcademicaMaxima(string formacaoAcademicaMaxima){
}