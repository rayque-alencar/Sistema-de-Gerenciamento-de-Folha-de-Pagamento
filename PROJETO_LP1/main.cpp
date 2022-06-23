#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <windows.h>
#include "Funcionarios.h"
#include "Gerente.h"
#include "Operador.h"
#include "Diretor.h"
#include "Presidente.h"
#include "Menu.h"

using namespace std;

int main(){

    Menu menu;
    int aux,aux2;
    int numeroDoFuncionario;

    //while para rodar o menu 
    while(1){

    menu.menuInicial();
    int opcao;
    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    cin.ignore();
    system("clear||cls");

        switch (opcao)   
        {
        //opcao para cadastrar funcionario
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
            system("pause");
            system("clear||cls");
            break;
        //opcao para editar funcionario
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
            system("pause");
            system("clear||cls");
            break;
        
        //opcao para excluir funcionario
        case 3:
            menu.excluirFuncionario();
            system("pause");
            system("clear||cls");
            break;

        //exibir um registro de um funcionario
        case 4:
            cout << "Digite o numero do funcionario: " << endl;
            cin >> numeroDoFuncionario;
            aux = menu.getFuncionarioPeloNumeroDoFuncionario(numeroDoFuncionario);
            system("clear||cls");
            menu.exibirFuncionario(aux);
            system("pause");
            system("clear||cls");
            break;
        //exibir todos os registros de funcionarios
        case 5:
            menu.exibirListaDeFuncionarios();
            system("pause");
            system("clear||cls");
            break;

        //conceder um aumento a todos os funcionario
        case 6: 
            menu.concederAumento();
            system("pause");
            system("clear||cls");
            break;

        //calcular folha salarial de todos os funcionarios
        case 7:
            menu.calcularFolhaSalarial();
            system("pause");
            system("clear||cls");
            break;

        //imprimir a folha salarial 
        case 8:
            menu.imprimeFolhaSalarialFuncionario();
            system("pause");
            system("clear||cls");
            break;

        //exibir folha salarial da empresa
        case 9:
            menu.exibirFolhaDaEmpresa();
            system("pause");
            system("clear||cls");
            break;

        //procurar funcionario
        case 10:
            menu.procurarFuncionario();
            system("pause");
            system("clear||cls");
            break;
        
        //procurar do tipo 
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

            system("pause");
            system("clear||cls");
            break;

        //ler Arquivo com funcionarios
        case 12:
            menu.lerArquivoFuncionario();
            system("pause");
            system("clear||cls");
            break;

        //salvar arquivo folha salarial
        case 13:
            cout << "digite o mes que deseja salvar a folha salarial: " << endl;
            int aux3;
            cin >> aux3;
            menu.salvarArquivoFuncionario(aux3);

        //finalizar programa
        case 14:
            system("clear||cls");
            menu.salvarArquivoFuncionario();
            cout << "Saindo do programa..." << endl;
            exit(0);
  
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }
    }

    return 0;
}
