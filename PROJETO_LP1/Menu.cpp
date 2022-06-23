#include "Menu.h"

Menu::Menu()
{
 
}

//metodo com o menu inicial, como todas ao opcoes do menu
void Menu::menuInicial(){
    
    cout << "--------------------------" << endl;
    cout << "      Menu principal" << endl;
    cout << "--------------------------\n" << endl;
    cout << "[1] - Adicionar um funcionario" << endl;
    cout << "[2] - Editar um registro de funcionario" << endl;
    cout << "[3] - Excluir um registro de funcionario" << endl;
    cout << "[4] - Exibir um registro de funcionario" << endl;
    cout << "[5] - Exibir todos os registros de funcionarios" << endl;
    cout << "[6] - Conceder aumento a todos os funcionarios" << endl;
    cout << "[7] - Calcular folha salarial" << endl;
    cout << "[8] - Exibir folha salarial do funcionario" << endl;
    cout << "[9] - Exibir folha salarial da empresa" << endl;
    cout << "[10] - Pesquisar funcionario" << endl;
    cout << "[11] - Pesquisar funcionario por designacao de designacao" << endl;
    cout << "[12] - Ler arquivo de Funcionarios" << endl;
    cout << "[0] - Finalizar Sistema" << endl;
    cout << "\n--------------------------\n" << endl;

}

//metodo para adicionar um funcionario
void Menu::adicionarFuncionario(){

    int numeroDoFuncionario, opcao, dia, mes, ano;
    string nome, CEP, telefone, designacao, numeroDaResidencia;
    float salario;
    
    cout << "Insira o codigo do funcionario: " << endl;
    cin >> numeroDoFuncionario;
    cin.ignore();
    
    //Verifica se o numeroDoFuncionario ja existe para nao ter funcionario com o mesmo numeroDoFuncionario
    for (int i = 0; i < vFuncionarios.size(); i++)
    {
        if (vFuncionarios[i]->getNumeroDoFuncionario() == numeroDoFuncionario)
        {
            throw 1;
        }
    }
    system("clear||cls");
    
    cout << "Insira o nome do funcionario: " << endl;
    getline(cin, nome);
    
    //Verifica se o nome ja existe para nao ter funcionario com o mesmo nome
    for (int i = 0; i < vFuncionarios.size(); i++)
    {
        if (vFuncionarios[i]->getNome().find(nome) != string::npos)
        {
            throw 2;
        }
    }
    system("clear||cls");

    cout << "Digite o CEP do Funcionario: " << endl;
    cout << "Exemplo: XXXXXXXXXX" << endl;
    getline(cin, CEP);
    system("clear||cls");

    cout << "Digite o numero da residencia: " << endl;
    getline(cin, numeroDaResidencia);
    system("clear||cls");

    cout << "Digite o telefone do funcionario " << endl;
    cout << "Formato de digitacao: (DDD)XXXX-XXXX" << endl;
    getline(cin, telefone);

    //Verifica se o telefone ja existe para nao ter funcionario com o mesmo telefone
    for (int i = 0; i < vFuncionarios.size(); i++)
    {
        if (vFuncionarios[i]->getTelefone() == telefone)
        {
            throw 3;
        }
    }
    system("clear||cls");

    cout << "Digite a data de contratacao do funcionario." << endl;
    cout << "Formato de digitacao: (DIA MES ANO)" << endl;
    cin >> dia >> mes >> ano;
    cin.ignore();
    system("clear||cls"); 

    Endereco endereco(CEP, numeroDaResidencia);
    Data dataDeIngresso(dia, mes, ano);

    cout << "--------------------------" << endl;
    cout << "Designacao do funcionario" << endl;
    cout << "--------------------------\n" << endl;
    cout << "[1] - Operador" << endl;
    cout << "[2] - Gerente" << endl;
    cout << "[3] - Diretor" << endl;
    cout << "[4] - Presidente" << endl;
    cout << "\n--------------------------\n" << endl;

    cout << "Digite a opcao desejada: ";
    cin >> opcao;
    system("clear||cls"); 

    cout << "Insira o salario: " << endl;
    cin >> salario;
    cin.ignore();
    system("clear||cls"); 

    Funcionarios *funcionario;

        switch (opcao){
        
        case 1:
            funcionario = new Operador(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Operador", salario);
            funcionario->LerAtributos(numeroDoFuncionario);
            break;
        
        case 2:
            funcionario = new Gerente(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Gerente", salario);
            funcionario->LerAtributos(numeroDoFuncionario);
            break;
    
        case 3:
            funcionario = new Diretor(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Diretor" ,salario);
            funcionario->LerAtributos(numeroDoFuncionario);
            break;
        
        case 4:
            funcionario = new Presidente(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Presidente" ,salario);
            funcionario->LerAtributos(numeroDoFuncionario);
            break;
        }
    
    
    vFuncionarios.push_back(funcionario); 

}

//metodo para exibir um registro de funcionario
void Menu::exibirFuncionario(int indice){
    
    cout << "----------------------------------------------\n";
    vFuncionarios[indice]->exibirAtributos();
    cout << "----------------------------------------------\n";
   
}

//metodo para exibir todos os registros de funcionarios
void Menu::exibirListaDeFuncionarios()
{
    for(int i = 0; i < vFuncionarios.size(); i++){
        exibirFuncionario(i);
    }
}

//metodo para procurar um registro de funcionario
void Menu::procurarFuncionario(){

    bool aux_busca = false; 
    int opcao, opcao2; 
    string nome, endereco; 

    cout << "Deseja buscar funcionario com?" << endl;
    cout << "[1] Nome" << endl;
    cout << "[2] Data de ingressao" << endl;
    cout << "[3] Endereco" << endl;
    cin >> opcao;
    system("clear||cls");
    cin.ignore();
   
    
    switch(opcao){

        case 1:
            cout << "Digite um nome do funcionário que voce deseja procurar" << endl;
            getline(cin, nome); 

            for(int i = 0; i < vFuncionarios.size(); i++){

                if(vFuncionarios[i]->getNome().find(nome) != string::npos){
                    aux_busca = true;
                    exibirFuncionario(i);
                }

            }

            if(aux_busca == false){
                cout << "Nenhum funcionario com esse nome foi encontrado." << endl;
            }
            break;

        case 2:
        
            int aux_dia, aux_mes, aux_ano; 
            int aux_dia2, aux_mes2, aux_ano2; 

            cout << "Digite a primeira data do intervalo (menor data)\n no formato (DIA MES ANO)" << endl;
            cin >> aux_dia >> aux_mes >> aux_ano;
            cin.ignore();

            cout << "Digite a segunda data do intervalo (maior data)\n no formato (DIA MES ANO)" << endl;
            cin >> aux_dia2 >> aux_mes2 >> aux_ano2;
            cin.ignore();

            for(int i = 0; i < vFuncionarios.size(); i++){
                
                if(vFuncionarios[i]->getDataDeIngresso().getAno() >= aux_ano and vFuncionarios[i]->getDataDeIngresso().getAno() <= aux_ano2){  
                    if(vFuncionarios[i]->getDataDeIngresso().getAno() == aux_ano and vFuncionarios[i]->getDataDeIngresso().getMes() >= aux_mes and vFuncionarios[i]->getDataDeIngresso().getMes()){ 
                        if(vFuncionarios[i]->getDataDeIngresso().getMes() == aux_mes and vFuncionarios[i]->getDataDeIngresso().getDia() >= aux_dia and vFuncionarios[i]->getDataDeIngresso().getDia()){
                            aux_busca = true;
                            exibirFuncionario(i);
                        }
                    }
                  
                    else if(vFuncionarios[i]->getDataDeIngresso().getAno() == aux_ano2 and vFuncionarios[i]->getDataDeIngresso().getMes() >= aux_mes2 and vFuncionarios[i]->getDataDeIngresso().getMes()){ 
                        if(vFuncionarios[i]->getDataDeIngresso().getMes() == aux_mes2 and vFuncionarios[i]->getDataDeIngresso().getDia() >= aux_dia2 and vFuncionarios[i]->getDataDeIngresso().getDia()){
                            aux_busca = true;
                            exibirFuncionario(i);
                        }
                    }

                    else if(vFuncionarios[i]->getDataDeIngresso().getAno() > aux_ano and vFuncionarios[i]->getDataDeIngresso().getAno() < aux_ano2){
                        aux_busca = true;
                        exibirFuncionario(i);
                    }                                                                           
                }
            }

            if(aux_busca == false){
                cout << "Nenhum funcionario dentro desse intervalo de datas foi encontrado." << endl;
            }

            break;

        case 3:

            int opcao3;
            cout << "Qual elementos você deseja usar para fazer a busca?" << endl;
            cout << "[1] Rua" << endl;
            cout << "[2] Bairro" << endl;
            cout << "[3] Cidade" << endl;
            cout << "[4] CEP" << endl;
            cin >> opcao3;
            cin.ignore();


            switch(opcao3){
            case 1:
            {
                string rua;
                cout << "Digite o nome da rua para fazer a busca." << endl;
                getline(cin, rua);

                for(int i = 0; i < vFuncionarios.size(); i++){
                    if(vFuncionarios[i]->getEndereco().getRua().find(rua) !=string::npos){
                        aux_busca = true;
                        exibirFuncionario(i);
                    }
                }
                break;
            }
             
            case 2:
            {
                string bairro;
                cout << "Digite o nome do bairro para fazer a busca." << endl;
                getline(cin, bairro);

                for(int i = 0; i < vFuncionarios.size(); i++){
                    if(vFuncionarios[i]->getEndereco().getBairro().find(bairro) != string::npos){
                        aux_busca = true;
                        exibirFuncionario(i);
                    }
                }
                break;
            }
            case 3:
            {
                string cidade;
                cout << "Digite o nome da cidade para fazer a busca." << endl;
                getline(cin, cidade);
            
                for(int i = 0; i < vFuncionarios.size(); i++){
                    if(vFuncionarios[i]->getEndereco().getCidade().find(cidade) != string::npos){
                        aux_busca = true;
                        exibirFuncionario(i);
                    }
                }
                break;
               
            }
            case 4:
            {
                string CEP;
                cout << "Digite o CEP para fazer a busca." << endl;
                getline(cin, CEP);

                for(int i = 0; i < vFuncionarios.size(); i++){
                    if(vFuncionarios[i]->getEndereco().getCep().find(CEP) != string::npos){
                        aux_busca = true;
                        exibirFuncionario(i);
                    }
                }       
                break;
            
            }
            default:
                cout << "Opcao invalida." << endl;
                break;
            }

            if(aux_busca == false){
                cout << "Nao existe nenhum funcionario com esse endereco na empresa." << endl;
            }
            break;
        
        default:
            cout << "Opcao invalida." << endl;
            break;
    
    }
   
}

//metodo para editar informacoes de um funcionario
void Menu::editarFuncionario(){

    int indice, procurar_Num_Funcionario, opcao, opcaoAux;
    int novoDia, novoMes, novoAno;
    int novoNumFuncionario;
    string novaVariavelAux, novaVariavelAux2;
    Data novaData(0, 0, 0);
    float novosalario;
    

    cout << "Insira o codigo do funcionario a se alterar: ";
    cin >> procurar_Num_Funcionario;
    
    indice = getFuncionarioPeloNumeroDoFuncionario(procurar_Num_Funcionario);

    cout << "-------------------------------" << endl; 
    cout <<"Opcoes disponivel para alteracao" << endl;
    cout << "-------------------------------" << endl; 
    cout <<"[1] codigo" << endl;
    cout <<"[2] Nome"  << endl;
    cout <<"[3] Endereco" << endl;
    cout <<"[4] Telefone" << endl;
    cout <<"[5] Data de Ingresso" << endl;
    cout <<"[6] Designacao" << endl;
    cout <<"[7] Salario" << endl;
     cout << "-------------------------------" << endl; 

    cin >> opcao;
    cin.ignore();

    switch(opcao)
    {
        case 1: //alterar numeroDoFuncionario 
            cout << "Qual o novo codigo do funcionario: ";
            cin >>novoNumFuncionario;
            cin.ignore();

            for (int i = 0; i < vFuncionarios.size(); i++)
            {
                if (vFuncionarios[i]->getNumeroDoFuncionario() == novoNumFuncionario)
                {
                    throw 1;
                }
            }

            vFuncionarios[indice]->setNumeroDoFuncionario(novoNumFuncionario);
            break;

        case 2: //alterar nome
            cout << "Qual o novo nome do funcionario: ";
            getline(cin, novaVariavelAux);
            
            for (int i = 0; i < vFuncionarios.size(); i++)
            {
                if (vFuncionarios[i]->getNome().find(novaVariavelAux) != string::npos)
                {
                    throw 2;
                }
            }

            vFuncionarios[indice]->setNome(novaVariavelAux);
            break;

        case 3: //alterar endereco
            cout <<"Qual o novo o novo CEP onde o funcionario mora: "; 
            getline(cin,novaVariavelAux);
            cout <<"Qual o novo numero onde o funcionario mora: ";
            getline(cin,novaVariavelAux2);
            vFuncionarios[indice]->setEndereco(novaVariavelAux, novaVariavelAux2);
            break;

        case 4: //alterar telefone
            cout << "Qual o novo telefone do funcionario: ";
            getline(cin, novaVariavelAux);

            for (int i = 0; i < vFuncionarios.size(); i++)
            {
                if (vFuncionarios[i]->getTelefone() == novaVariavelAux)
                {
                    throw 3;
                }
            }

            vFuncionarios[indice]->setTelefone(novaVariavelAux);
            break;

        case 5: //alterar dataIngresso
            cout << "Qual a nova data de ingresao do funcionario (DIA MES ANO): " << endl;
            cin >> novoDia >> novoMes >> novoAno;
            cin.ignore();

            novaData.setDia(novoDia);
            novaData.setMes(novoMes);
            novaData.setAno(novoAno);

            vFuncionarios[indice]->setDataDeIngresso(novaData);
            break;
        
        case 6: //alterar designacao
            cout << "Insira a nova designacao" << endl;
            cout << "[1] Operador" << endl;
            cout << "[2] Gerente" << endl;
            cout << "[3] Diretor" << endl;
            cout << "[4] Presidente" << endl;

            cin >> opcaoAux;
            cin.ignore();

            if(opcaoAux== 1){         
                vFuncionarios[indice]->setDesignacao("Operador");
            }else if(opcaoAux== 2){       
                vFuncionarios[indice]->setDesignacao("Gerente");
            }else if(opcaoAux == 3){     
                vFuncionarios[indice]->setDesignacao("Diretor");
            }else if(opcaoAux == 4){         
                vFuncionarios[indice]->setDesignacao("Presidente");
            }
            break;

        case 7: //alterar  salario
            cout << "Insira o novo salario do funcionario: ";
            cin >> novosalario;
            vFuncionarios[indice]->setSalario(novosalario);
            break;
    }


}

//metodo para retornar o indice(local onde ele estar no vector) do funcionario pelo numero do funcionario
int Menu::getFuncionarioPeloNumeroDoFuncionario(int numeroDoFuncionario)
{
    int indice;

    for(int i= 0; i < vFuncionarios.size(); i++)
    {
        if(vFuncionarios[i]->getNumeroDoFuncionario() == numeroDoFuncionario)
        {
            indice = i;
            return indice;
        }         
    }
    return -1;
}

//medodo para excluir um funcionario
void Menu::excluirFuncionario(){

    int numeroDoFuncionario, indice;
    string designacao;
    bool funcionarioEncontrado = false, confirmacao = false;

    cout << "Digite o codigo do funcionario que deseja excluir: ";
    cin >> numeroDoFuncionario;

    for(int i= 0; i < vFuncionarios.size(); i++){     
        if(vFuncionarios[i]->getNumeroDoFuncionario() == numeroDoFuncionario){
            indice = i;
            funcionarioEncontrado = true;
            designacao = vFuncionarios[i]->getDesignacao();
            break;
        }
    }

    if(funcionarioEncontrado == false){    

        cout << "Funcionario nao encontrado" << endl; 

    }else if(funcionarioEncontrado == true && designacao == "Diretor"||designacao == "Presidente"){
            cout << "O funcionario nao pode ser excluido." << endl;

    }else if(funcionarioEncontrado == true){

            cout << "Voce tem certeza que quer apagar o funcionario do codigo: " << vFuncionarios[indice]->getNumeroDoFuncionario() << endl;
            cout << "[1] Sim" << endl;
            cout << "[0] Nao" << endl;
            cin >> confirmacao;

            if(confirmacao==true){
                vFuncionarios.erase(vFuncionarios.begin() + indice);
                cout << "Funcionario removido com sucesso!" << endl;
            }else if(confirmacao==false){
                cout << "Operacao cancelada." << endl;
            }
    }
}

//metodo para exibir todos os funcionarios por designacao  
void Menu::exibirFuncionariosPorTipo(string designacao){
    
    for(int i= 0; i < vFuncionarios.size(); i++){
        
        if(vFuncionarios[i]->getDesignacao() == "Operador" and designacao == vFuncionarios[i]->getDesignacao()){
            cout << "-------------------------------" << endl;
            vFuncionarios[i]->exibirAtributos();
            cout << "-------------------------------" << endl;
        }else if (vFuncionarios[i]->getDesignacao() == "Gerente" and designacao == vFuncionarios[i]->getDesignacao()){
            cout << "-------------------------------" << endl;
            vFuncionarios[i]->exibirAtributos();
            cout << "-------------------------------" << endl;
        }else if (vFuncionarios[i]->getDesignacao() == "Diretor" and designacao == vFuncionarios[i]->getDesignacao()){
            cout << "-------------------------------" << endl;
            vFuncionarios[i]->exibirAtributos();
            cout << "-------------------------------" << endl;
        }else if (vFuncionarios[i]->getDesignacao() == "Presidente" and designacao == vFuncionarios[i]->getDesignacao()){
            cout << "-------------------------------" << endl;
            vFuncionarios[i]->exibirAtributos();
            cout << "-------------------------------" << endl;
        }
    }
}

//metodo para conceder um aumento a todos os funcionarios
void Menu::concederAumento(){

    for(int i = 0; i < vFuncionarios.size(); i++){
        vFuncionarios[i]->aumentoSalario();
    }
    cout << "Aumento nos salarios realizado com sucesso!" << endl;
}

//metodo para setar dias aleatorios para os funcionarios
void Menu::setDiasAleatorios(int mes, int indice)
{
    int dias;  
    srand(time(NULL));

     while(1){
        dias = 1 + rand() % 23;

        if(dias < 19){
            continue;
        }else{
            break;
        }
    }

    vFuncionarios[indice]->setDiasTrabalhados(dias, mes);
}

//metodo para setar horas aleatorias para os funcionarios
void Menu::setHorasAleatorias(int mes, int indice)
{
    int horas;
    srand(time(NULL) + indice);
    horas = 1 + rand() % 40;

    vFuncionarios[indice]->setHorasExtras(horas, mes);

}

//metodo para calcular a folha salarial 
void Menu::calcularFolhaSalarial()
{
    int mes;
    cout << "Qual mes deseja calcular a folha salarial: " << endl;
    cout << "[1] Janeiro" << endl;
    cout << "[2] Fevereiro" << endl;
    cout << "[3] Marco" << endl;
    cout << "[4] Abril" << endl;
    cout << "[5] Maio" << endl;
    cout << "[6] Junho" << endl;
    cout << "[7] Julho" << endl;
    cout << "[8] Agosto" << endl;
    cout << "[9] Setembro" << endl;
    cout << "[10] Outubro" << endl;
    cout << "[11] Novembro" << endl;
    cout << "[12] Dezembro" << endl;
    
    cin >> mes;

    //se o calculo ja foi feito para o mes, retorno ao menu com esssa mensagem
    if(folhaSalarialCalculada[mes-1] == 1){
        cout << "A folha salarial desse mes já foi calculada." << endl;

    //fazer o calculo da folha salarial
    }else{
        for(int i = 0; i < vFuncionarios.size(); i++){
            setDiasAleatorios(mes, i);
            setHorasAleatorias(mes, i);
            vFuncionarios[i]->calculaFolhaMensal(vFuncionarios[i]->getSalario(), mes);
        }
    cout << "Folha salarial calculada com sucesso!" << endl;

        folhaSalarialCalculada[mes-1] = 1;
    }
    
}

//metodo para exibir a folha salarial
void Menu::imprimeFolhaSalarialFuncionario() 
{
    int opcao, indice, mes;

    cout << "Deseja imprimir pelo numero do funcionario ou nome?" << endl;
    cout <<"[1] Numero do funcionario" << endl;
    cout <<"[2] Nome do funcionario" << endl;
    cin >> opcao;
    cin.ignore();
    system("clear||cls");

    if(opcao == 1){
        long numeroDoFuncionario;

        cout << "Digite o numero do funcionario: " << endl;
        cin >> numeroDoFuncionario;   

        indice = getFuncionarioPeloNumeroDoFuncionario(numeroDoFuncionario);
    }else if(opcao == 2){

        string nome;
        cout << "Digite o nome do funcionario: " << endl;
        getline(cin, nome);
        
        indice = getFuncionarioPorNome(nome);
    }else{  
        cout << "Opcao invalida" << endl;
        return;
    }
    system("clear||cls");

    cout << "Digite o mes que deseja imprimir a folha salarial: " << endl;
    cin >> mes;

    if(folhaSalarialCalculada[mes-1] == true)
    {
        vFuncionarios[indice]->imprimirFolhaSalarial(mes);
    }else{
        cout << "Folha desse mes ainda nao foi calculada!" << endl;   
    }

}

//metodo para retornar o index (onde ele esta salvo no vector) do funcionario pelo nome do funcionario
int Menu::getFuncionarioPorNome(string nome)
{
    int indice;

    for(int i= 0; i < vFuncionarios.size(); i++)
    {
        
        if(vFuncionarios[i]->getNome() == nome)
        {
            indice= i;
            return indice;
        }
    }
    
    return 0;
}

//metodo para exibir a folha anual da empresa
void Menu::exibirFolhaDaEmpresa(){

    int opcao;

    cout << "Deseja imprimir uma folha mensal ou a folha anual?"<< endl;
    cout << "[1] Mensal" << endl;
    cout << "[2] Anual" << endl;
    cin >> opcao;
    system("clear||cls");

    if(opcao == 1){
        int mes;

        cout << "Digite o mes que voce deseja exibir: " << endl;
        cout << "[1] Janeiro" << endl;
        cout << "[2] Fevereiro" << endl;
        cout << "[3] Março" << endl;
        cout << "[4] Abril" << endl;
        cout << "[5] Maio" << endl;
        cout << "[6] Junho" << endl;
        cout << "[7] Julho" << endl;
        cout << "[8] Agosto" << endl;
        cout << "[9] Setembro" << endl;
        cout << "[10] Outubro" << endl;
        cout << "[11] Novembro" << endl;
        cout << "[12] Dezembro" << endl;
        cin >> mes;
        system("clear||cls");

        cout << "Folha do mes com o salario bruto do funcionario: " << mes << endl;

        float totalFolhaMensal = 0;

        //calculando o total da folha mensal
        for(int i = 0; i < vFuncionarios.size(); i++){
            totalFolhaMensal += vFuncionarios[i]->getSalario(); 
        }

        cout << "Total da folha mensal: R$ " << totalFolhaMensal << endl;

    }

    if(opcao == 2){

        cout << "Folha Anual" << endl;
        float totalFolhaAnual = 0;

        for(int i = 0; i < vFuncionarios.size(); i++){
            totalFolhaAnual += vFuncionarios[i]->getSalario(); 
        }

        cout << "Total: R$ " << totalFolhaAnual * 12 << endl;

              
        
    }else{
        cout << "Opcao invalida" << endl;
    }

}

//metodo para ler arquivo com informacoes de funcionarios
void Menu::lerArquivoFuncionario(){
    int quantidadeDeFuncionariosParaAdd = 0, quantidadeDeFuncionarios = 0;  
    fstream arquivo;

        //abrindo o arquivo
        arquivo.open("Funcionarios.txt", fstream::in);

        //criar arquivo de funcionarios se nao existir 
        if(arquivo.is_open() == false){
            arquivo.open("Funcionarios.txt", ios::out);                                 
            arquivo.close();
        }

        //ler o arquivo e adicionar os funcionarios ao vector
        while(1){
            if(arquivo.eof()){
                break;
            }

            string linhas;

            getline(arquivo, linhas);
            if(linhas == "/"){
                quantidadeDeFuncionariosParaAdd++;
            }
        }

        arquivo.close();
        arquivo.open("Funcionarios.txt", fstream::in);
        
        while(1){
            
            //if para verificar se o arquivo esta vazio e sair do while
            if(quantidadeDeFuncionarios == quantidadeDeFuncionariosParaAdd){
                cout << "funcionarios lidos com sucesso!" << endl;
                break;
            }

            string linha,nome, cep,numero,telefone,areaDeSupervisao, areaDeFormacao;
            int numeroDoFuncionario;
            int dia, mes, ano;
            int designacao;
            float salario;
            
            getline(arquivo, linha);

            quantidadeDeFuncionarios++;
            arquivo >> numeroDoFuncionario;
            arquivo.ignore();
            getline(arquivo, nome);
            getline(arquivo, cep);
            getline(arquivo, numero);
            getline(arquivo, telefone);
            arquivo >> dia >> mes >> ano;
            arquivo >> designacao;
            arquivo >> salario;
            arquivo.ignore();

            Data  dataDeIngresso(dia, mes, ano);
            Endereco endereco(cep, numero);
            Funcionarios *funcionario;

            //verificar qual o tipo de funcionario e criar o objeto
            switch (designacao){

            case 1:
                funcionario = new Operador(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Operador", salario);
                break;
            
            case 2:
                getline(arquivo, areaDeSupervisao);
                funcionario = new Gerente(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso, "Gerente", salario, areaDeSupervisao);
                break;
            
            case 3:
                getline(arquivo, areaDeSupervisao);
                getline(arquivo, areaDeFormacao);
                funcionario = new Diretor(numeroDoFuncionario, nome, endereco, telefone,  dataDeIngresso,"Gerente", salario, areaDeSupervisao, areaDeFormacao);
                break;
            
            case 4:
                string formacaoMaxima;
                getline(arquivo, areaDeFormacao);
                getline(arquivo, formacaoMaxima);
                funcionario = new Presidente(numeroDoFuncionario, nome, endereco, telefone, dataDeIngresso,"Presidente", salario, areaDeFormacao, formacaoMaxima);
                break;
            }

            vFuncionarios.push_back(funcionario);
        }
        arquivo.close();
    
}

//metodo para salvar arquivo de funcionarios
void Menu::salvarArquivoFuncionario(){
    fstream arquivo;

    //abrindo o arquivo
    arquivo.open("FuncionariosFinal.txt", fstream::out);

    //criar arquivo de funcionarios se nao existir
    if(arquivo.is_open()== false){
            arquivo.open("FuncionariosFinal.txt", ios::out);                                 
    }

    //salvar os funcionarios no arquivo
    for(int i = 0; i < vFuncionarios.size(); i++){
        
        arquivo << "/" << endl;
        //numero do funcionario e nome
        arquivo << vFuncionarios[i]->getNumeroDoFuncionario() << endl;
        arquivo << vFuncionarios[i]->getNome() << endl;

        //Endereco
        arquivo << vFuncionarios[i]->getEndereco().getRua() << endl;
        arquivo << vFuncionarios[i]->getEndereco().getNumero() << endl;
        arquivo << vFuncionarios[i]->getEndereco().getBairro() << endl;
        arquivo << vFuncionarios[i]->getEndereco().getCidade() << endl;
        arquivo << vFuncionarios[i]->getEndereco().getEstado() << endl;
        arquivo << vFuncionarios[i]->getEndereco().getCep() << endl;
        
        //Telefone
        arquivo << vFuncionarios[i]->getTelefone() << endl;

        //Data de ingresso
        arquivo << vFuncionarios[i]->getDataDeIngresso().getDia() << endl;
        arquivo << vFuncionarios[i]->getDataDeIngresso().getMes() << endl;
        arquivo << vFuncionarios[i]->getDataDeIngresso().getAno() << endl;

        //Designacao e salario 
        arquivo << vFuncionarios[i]->getDesignacao() << endl;
        arquivo << vFuncionarios[i]->getSalario() << endl;
        
        //verificar qual o tipo de funcionario e salvar os dados
        if(vFuncionarios[i]->getDesignacao() == "Gerente")
        {
            arquivo << vFuncionarios[i]->getAreaSupervisao() << endl;
        }
        else if(vFuncionarios[i]->getDesignacao() == "Diretor")
        {
            arquivo << vFuncionarios[i]->getAreaSupervisao()<< endl;
            arquivo << vFuncionarios[i]->getAreaDeFormacao()<< endl;
        }
        else if(vFuncionarios[i]->getDesignacao()=="Presidente")
        {
            arquivo << vFuncionarios[i]->getAreaDeFormacao()<< endl;
            arquivo << vFuncionarios[i]->getFormacaoAcademicaMaxima()<< endl;
        }
    }

    arquivo.close();
}