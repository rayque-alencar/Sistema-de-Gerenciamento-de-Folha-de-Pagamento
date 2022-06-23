#include "Endereco.h"

Endereco::Endereco()
{

}

//constructor do endereco
Endereco::Endereco(string cep, string numero){
    setCep(cep);
    setNumero(numero);
    //chamando o metodo para pegar os dados do endereco com o cep
    parseCEP();
}

//lsita de metodos getters
string Endereco::getRua()
{
    return rua;
}

string Endereco::getBairro()
{
    return bairro;
}

string Endereco::getCidade()
{
    return cidade;
}

string Endereco::getEstado()
{
    return estado;
}

string Endereco::getCep()
{
    return cep;
}

string Endereco::getNumero()
{
    return numero;
}

//lista de metodos setters
void Endereco::setRua(string rua){

    this -> rua = rua;
}

void Endereco::setBairro(string bairro){

    this -> bairro = bairro;
}

void Endereco::setCidade(string cidade){

    this -> cidade = cidade;
}

void Endereco::setEstado(string estado){

    this -> estado = estado;
}

void Endereco::setCep(string cep){

    this -> cep = cep;
}

void Endereco::setNumero(string numero){

    this -> numero = numero;
}

//metodo para imprimir os dados do endereco
void Endereco::exibirEnderecoCompleto(){

    cout << "Endereco do funcionario: " << rua << ", " << numero << ", " << bairro << ", " << cidade << ", " << estado << ", " << cep << endl; 

}

//metodo para pegar os dados do endereco com o cep, de acordo com o que foi ensinado em aula
void Endereco::parseCEP()
{
    string url, linha, rua, bairro, cidade, estado; 
    fstream fs; 
    int i = 0; 

    url = "https://viacep.com.br/ws/" + cep + "/json/";
    system(("wget -q -O cep.txt " + url).c_str()); 

    fs.open("CEP.txt", fstream::in); 
    if(fs.is_open()){ 

        while(!fs.eof()){ 
                getline(fs, linha);
                
                //rua  
                if(i == 2){ 
                    rua = linha.substr(17, linha.size() - 2 - 17);
                    setRua(rua);
                }
                //bairro
                if(i == 4){ 
                    bairro = linha.substr(13, linha.size() - 2 - 13);
                    setBairro(bairro);
                }
                //cidade
                if(i == 5){ 
                    cidade = linha.substr(17, linha.size() - 2 - 17);
                    setCidade(cidade);
                }
                //estado
                if(i == 6){ 
                    estado = linha.substr(9, linha.size() - 2 - 9);
                    setEstado(estado);
                }
                i++; 
        }
        fs.close(); 
    }
}