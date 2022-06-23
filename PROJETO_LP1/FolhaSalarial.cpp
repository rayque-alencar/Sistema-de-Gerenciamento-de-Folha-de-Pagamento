#include "FolhaSalarial.h"

FolhaSalarial::FolhaSalarial()
{
    
}

//metodo para calcular o INSS, calculo tirado da internet
void FolhaSalarial::calcularINSS(float salario){

    if(salario <= 1212){
        INSS = salario*0.075;    
    }else if(salario > 1212 && salario <= 2427.35){
        INSS = 90.9 + (salario - 1212)*0.09;
    } else if(salario > 2427.35 && salario <= 3641.03){
        INSS = 90.9 + 109.38 + (salario - 2427.36)*0.12;
    } else if(salario > 3641.03 && salario <= 7087.22){
        INSS = 90.9 + 109.38 + 145.64 + (salario - 3641.03)*0.14;
    } else {
        INSS = 828.38;
    } 

}

//metodo para calcular o IRRF, calculo tirado da internet
void FolhaSalarial::calcularIRRF(float salario){

    if(salario <= 1903.98){
        IRRF = 0;
    } else if(salario > 1903.98 && salario <= 2826.65){
        IRRF = (salario - INSS)*0.075 - 142.80;
    } else if(salario > 2826.65 && salario <= 3751.05){
        IRRF = (salario - INSS)*0.15 - 354.80;
    } else if(salario > 3751.05 && salario <= 4664.68){
        IRRF = (salario - INSS)*0.225 - 636.13;
    } else {
        IRRF = (salario - INSS)*0.275 - 869.36;
    }  

}

//metodo para calcular o salario liquido
void FolhaSalarial::calcularSalarioLiquido(float salario){

    salarioLiquido = salario - INSS - IRRF;

}

//metodo para calcular o salario mensal
void FolhaSalarial::calcularSalarioMensal(float salario){

    float horaTotalMes = diasTrabalhados * 8; //para saber o total de horas trabalhado no mes, maximo de 8 horas pro dia
    float valorHora = salario/horaTotalMes;   //para saber o valor da hora trabalhada
    salarioExtra = horasExtras*valorHora*2;   //para saber o valor ganho com as horas extras

    salarioMesBrutoComHorasExtras = salarioLiquido + salarioExtra; //salario bruto com as horas extras

}

//metodos set
void FolhaSalarial::setDiasTrabalhados(float diasTrabalhados){
    this->diasTrabalhados = diasTrabalhados;
}

void FolhaSalarial::setHorasExtras(float horasExtras){
    this->horasExtras = horasExtras;
}

//metodos get
float FolhaSalarial::getINSS(){
    return INSS;
}

float FolhaSalarial::getIRRF(){
    return IRRF;
}

float FolhaSalarial::getSalarioLiquido(){
    return salarioLiquido;
}

float FolhaSalarial::getSalarioMesBrutoComHorasExtras(){
    return salarioMesBrutoComHorasExtras;
}

float FolhaSalarial::getsalario(){
    return salario;
}

float FolhaSalarial::getSalarioExtra(){

    return salarioExtra;
}

float FolhaSalarial::getDiasTrabalhados(){
    return diasTrabalhados;
}

float FolhaSalarial::getHorasExtras(){
    return horasExtras;
}