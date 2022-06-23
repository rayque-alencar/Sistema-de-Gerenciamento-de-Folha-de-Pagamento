#include <iostream>
#include <string>
#include <fstream>
#include "Funcionarios.h"
#include "Gerente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Menu.h"

using namespace std;

int main(){

    Menu menu;
    int opcao;
    int aux,aux2;
    int numeroDoFuncionario;

    while(1){
    
    menu.menuInicial();
    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    system("clear||cls");

        switch (opcao)   
        {
        case 1:
            try
            {
                menu.adicionarFuncionario();

            }catch(int mensagemDeErro)
            {
                if (mensagemDeErro == 1)
                {
                    cout << "Ja existe um funcionario com esse codigo!" << endl;
                }else if(mensagemDeErro == 2)
                {
                    cout << "Ja existe um funcionario com esse nome!" << endl;
                }else if (mensagemDeErro == 3)
                {
                    cout << "Ja existe um funcionario com esse telefone!" << endl;
                }   
            }
            break;

        case 2:

            try{
                menu.editarFuncionario();

            }catch(int mensagemDeErro)
            {
                if (mensagemDeErro == 1)
                {
                    cout << "ja existe um funcionario com esse codigo!" << endl;
                }else if(mensagemDeErro == 2)
                {
                    cout << "ja existe um funcionario com esse nome!" << endl;
                }else if (mensagemDeErro == 3)
                {
                    cout << "ja existe um funcionario com esse telefone!" << endl;
                }   
            }
            break;

        case 3:
            menu.excluirFuncionario();
            break;

        case 4:
            cout << "Digite o numero do funcionario: " << endl;
            cin >> numeroDoFuncionario;
            aux = menu.getFuncionarioPeloNumeroDoFuncionario(numeroDoFuncionario);
            system("clear||cls");
            menu.exibirFuncionario(aux);
            break;

        case 5:
            menu.exibirListaDeFuncionarios();
            break;

        case 6: 
            menu.concederAumento();
            break;

        case 7:
            menu.calcularFolhaSalarial();
            break;

        case 8:
            menu.imprimeFolhaSalarialFuncionario();
            break;

        case 9:
            menu.exibirFolhaDaEmpresa();
            break;

        case 10:
            menu.procurarFuncionario();
            break;
        
        case 11:
            cout << "Qual o tipo do funcionario que deseja buscar. " << endl;
            cout << "[1] Operador" << endl;
            cout << "[2] Gerente" << endl;
            cout << "[3] Diretor" << endl;
            cout << "[4] Presidente" << endl;     
            cin >>  aux2;
            cin.ignore();
            system("clear||cls");

                switch (aux2){
                case 1:
                    menu.exibirFuncionariosPorTipo("Operador");
                    break;
                case 2:
                    menu.exibirFuncionariosPorTipo("Gerente");
                    break;
                case 3:
                    menu.exibirFuncionariosPorTipo("Diretor");
                    break;
                case 4:
                    menu.exibirFuncionariosPorTipo("Presidente");
                    break;
                }

            break;

        case 12:
            menu.lerArquivoFuncionario();
            break;

        case 0:
            system("clear||cls");
            menu.salvarArquivoFuncionario();
            cout << "Saindo do programa..." << endl;
            exit(0);

        }
     
    }

    return 0;
}
