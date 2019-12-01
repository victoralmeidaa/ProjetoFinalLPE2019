#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 /* ESTRUTURAS */
typedef struct Cliente{ //ESTRUTURA DO TIPO CLIENTE
    char nome[50];
    char cpf[10];
    char endereco[50];
    int idCli;
}
Cliente;

typedef struct Carro{ //ESTRUTURA DO TIPO CARRO
    char modelo[20];
    char cor[20];
    char placa[10];
    int idCar;
    int idCli;
}
Carro;

typedef struct Funcionario{ //ESTRUTURA DO TIPO FUNCINARIO
    char nome[20];
    char cpf[10];
    char endereco[50];
    int idFun;
}
Funcionario;

typedef struct Servico{ //ESTRUTURA DO TIPO SERVICO
    char titulo[20];
    char descricao[50];
    int idServ;
    int idFun;
    int idCar;
}
Servico;

/* FUNÇÓES */
Cliente GetCliente(){ //FUNCAO DO TIPO CLIENTE PARA LER DADOS DO CLIENTES
    Cliente cli;//CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CLIENTE.
    printf("NOME: ");
    setbuf(stdin,NULL);
    gets(&cli.nome);
    printf("CPF: ");
    setbuf(stdin,NULL);
    gets(&cli.cpf);
    printf("ENDERECO: ");
    setbuf(stdin,NULL);
    gets(&cli.endereco);
    printf("ID: ");
    scanf("%d",&cli.idCli);
    return cli;//FUNCAO RETORNA ESTRUTURA DO TIPO CLIENTE.
}

Carro GetCarro(){ //FUNCAO DO TIPO CARRO PARA LER DADOS DE CARROS.
    Carro car;//CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CARRO.
    printf("MODELO: ");
    setbuf(stdin,NULL);
    gets(&car.modelo);
    printf("COR: ");
    setbuf(stdin,NULL);
    gets(&car.cor);
    printf("PLACA: ");
    setbuf(stdin,NULL);
    gets(&car.placa);
    printf("ID CARRO:");
    scanf("%d",&car.idCar);
    return car;//FUNCAO RETORNA ESTRUTURA DO TIPO CARRO.
}

Funcionario Getfuncionario(){ //FUNCAO DO TIPO FUNCIONARIO PARA LER DADOS DE CARROS
    Funcionario fun;//CRIANDO VAREAVEL DE ESTRUTURA DO TIPO FUNCIONARIO.
    printf("NOME: ");
    setbuf(stdin,NULL);
    gets(&fun.nome);
    printf("CPF: ");
    setbuf(stdin,NULL);
    gets(&fun.cpf);
    printf("ENDERECO: ");
    setbuf(stdin,NULL);
    gets(&fun.endereco);
    printf("ID: ");
    scanf("%d",&fun.idFun);
    return fun;//FUNCAO RETORNA ESTRUTURA DO TIPO FUNCIONARIO.
}

Servico GetServico(){ //FUNCAO PARA LER DADOS DE CARROS
    Servico serv;//CRIANDO VAREAVEL DE ESTRUTURA DO TIPO SERVICO.
    printf("TITULO: ");
    setbuf(stdin,NULL);
    gets(&serv.titulo);
    printf("DESCRICAO: ");
    setbuf(stdin,NULL);
    gets(&serv.descricao);
    printf("ID SERVICO: ");
    scanf("%d",&serv.idServ);
    return serv; //FUNCAO RETORNA ESTRUTURA DO TIPO SERVICO.
}

/*   FUNCAO MENU    */
void menu(){ //INICIO FUNCAO MENU
    int opcao;
    do //INICIO LACO DO MENU
    {
        printf("|-------------------------------|\n");
        printf("|    GERENCIADOR DE LAVAJATO    |\n");
        printf("|-------------------------------|\n");
        printf("|-------------------------------|\n");
        printf("|  1  |       CLIENTE           |\n");
        printf("|-------------------------------|\n");
        printf("|  2  |       SERVICO           |\n");
        printf("|-------------------------------|\n");
        printf("|  3  |       FUNCIONARIOS      |\n");
        printf("|-------------------------------|\n");
        printf("|  4  |       SAIR              |\n");
        printf("|-------------------------------|\n");
        printf("| Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch(opcao){// OPCOES DO MENU.
            case 1:{ //INICIO CASO 1 MENU/CLIENTE. SUBMENU CLIENTE
                int escolha_cliente;
                printf("|-------------------------------|\n");
				printf("|             CLIENTE           |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
				printf("|  3  |     LISTAR CLIENTE      |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |     LISTAR CARRO        |\n");
				printf("|-------------------------------|\n");
				printf("|  5  |     EXCLUIR CLIENTE     |\n");
				printf("|-------------------------------|\n");
				printf("|  6  |     EXCLUIR CARRO       |\n");
				printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&escolha_cliente);
				system("cls");

                switch(escolha_cliente){
                    case 1:{
                        int consultaID;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o ID do Cliente: ");
                        scanf ("%d",&consultaID);
                        int confirmaSeClienteExiste = 0; //SE 0 == CLIENTE NAO EXISTE  |  SE 1 == CLIENTE EXISTE.
						Cliente cli;
						Carro car;
						int auxIDCli; // AUXILIAR PARA GUARDA ID DO CLIENTE QUE FOI CONSULTADO.
						FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO.
						arq_cliente = fopen("arquivo_cliente.txt", "r"); //ABRIR ARQUIVO CLIENTE.
						while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli)!= EOF){ //LACO PARA LER TODAS AS LINHAS DO ARQUIVO
                            if(consultaID == cli.idCli){//CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                printf("\n=== DADOS CLIENTE ===\nNOME: %s\nCPF: %s\nENDERECO: %s\nID CLIENTE: %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //RETORNA OS DADOS DO CLIENTE DESEJADO
                                confirmaSeClienteExiste = 1; //SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CLIENTE EXISTE, VAREAVEL RECEBE 1.
                                auxIDCli = cli.idCli; //GUARDANDO O ID DO CLIENTE CONSULTADO NA VAREAVEL AUXILIAR.
                            } //FIM DA CONDICIONAL
						}// FIM DO LACO.
						if(confirmaSeClienteExiste == 0){//SO ENTRA NESSA CONDICAO CASO O CLIENTE NAO EXISTA, VALOR DA VAREAVEL == 0.
                                printf("\nCLIENTE NAO ENCONTRADO\n");// PRINTA MENSAGEM
                                system("pause");
                                system("cls");
                                break;//ENCERRA A CONTINUACAO DO PROGRAMA E VOLTA PARA O MENUR PRINCIPAL.
                        }
                        int confirmaSeCarroExiste = 0;// SE O == CARRO NÃO EXISTE  |  SE 1 == CARRO EXISTE.
                        int numerosCarros = 1;//VAREAVEL PARA CONTAR O NUMEROS DE CARROS DO CLIENTE, INICIALMENTE RECEBE 1.
						FILE *arq_carro; // PONTEIRO PARA ARQUIVO CARRO
						arq_carro = fopen("arquivo_carro.txt", "r"); // ABRIR ARQUIVO CARRO
						if (confirmaSeClienteExiste == 1){//CONDICIONAL PARA PERMITIR CADASTRAR UM CARRO APENAS SE EXISTIR UM CLIENTE DONO DESTE CARRO, PARA NÃO PERMITIR QUE SEJA CADASTRADO UM CARRO SEM UM CLIENTE ASSOCIADO A ELE.
                            while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli)!= EOF){ //LER TODAS AS LINHAS DO ARQUIVO
                                if(consultaID == car.idCli){//CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO, CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                    printf("\n=== DADOS DO CARRO %d ===\nMODELO: %s\nCOR: %s\nPLACA: %s\nID CARRO: %d\n",numerosCarros,car.modelo,car.cor,car.placa,car.idCar); //RETORNA OS DADOS
                                    numerosCarros++;//INCREMENTA NUMEROS DE CARROS CADASTRADOS.
                                    confirmaSeCarroExiste = 1;//SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CARRO EXISTE, VAREAVEL RECEBE 1.
                                }//FIM DA CONDICIONAL
                            }//FIM DO LACO
                            if(confirmaSeCarroExiste == 0){//SO ENTRA NESSA CONDICAO CASO CARRO NAO EXISTA, VALOR DA VAREAVEL == 0.
                                printf("\nCLIENTE NAO TEM CARRO CADASTRADO\n");//PRINTA MENSAGEM.
                            }
						}
						fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE.
						fclose(arq_carro);  //FECHAR ARQUIVO CARRO.
						system("pause");
						system("cls");

                            int escolha_carro;
                            char mensagemCar[20];// VARIAVEL PARA MENSAGEM DE COMPREMENTO DE DIALOGO
                            do // LACO PARA CADASTRAR CARRO.
                            {
                            if(confirmaSeCarroExiste == 0){//SE O CLIENTE NÃO TIVER CARRO CADASTRADO A MENNSAGEM SERA "UM CARRO".
                                strcpy(mensagemCar, "UM CARRO");//FUNCAO PARA COPIAR "STRING"(MESAGEM) PARA DENTRO DA VAREAVEL
                            }else{// SE O CLIENTE TIVER PELO MENOS UM CARRO CADASTRADO A MENSAGEM SERA "UM NOVO CARRO".
                                strcpy(mensagemCar, "UM NOVO CARRO");//FUNCAO PARA COPIAR "STRING"(MENSAGEM) PARA DENTRO DA VAREAVEL
                            }
                            printf("|-------------------------------|\n");
                            printf("|        CADASTRAR CARRO        |\n");
                            printf("|-------------------------------|\n");
                            printf("|-------------------------------|\n");
                            printf("|  1  |          SIM            |\n");
                            printf("|-------------------------------|\n");
                            printf("|  2  |          NAO            |\n");
                            printf("|-------------------------------|\n");
                            printf("DESEJA CADASTRAR %s PARA ESTE CLIENTE?: ",mensagemCar);//COLOCA A MENSAGEM ENTRE A PALAVRA COM O %S.
                            scanf("%d",&escolha_carro);
                            switch(escolha_carro){
                                case 1:{
                                    printf("|-------------------------------|\n");
                                    printf("|        CADASTRAR CARRO        |\n");
                                    printf("|-------------------------------|\n");
                                    FILE *arq_carro;
                                    arq_carro = fopen("arquivo_carro.txt", "a"); //ABRIR ARQUIVO CARRO.
                                    if(arq_carro ==  NULL){ //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CARRO.
                                        printf("ERRO NA ABERTURA DO ARQUIVO!"); //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO.
                                    }
                                    Carro car;
                                    car = GetCarro();
                                    car.idCli = auxIDCli;// ID CLIENTE QUE TINHA SIDO GUARDADA PELO AUXILIAR E ASSOCIADO AO ID DE CLIENTE QUE CONTEM NA ESTRUTURA CARRO.
                                    fprintf(arq_carro,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli); //GRAVAR DADOS DO "CAR" CARRO NO ARQUIVO CARRO
                                    fclose(arq_carro); //FECHAR ARQUIVO CARRO
                                    printf("Carro Cadastrado com Sucesso\n"); //MENSAGEM DE CONCLUSSAO
                                    confirmaSeCarroExiste = 1;//DEPOIS DE CADASTRAR UM CARRO A VAREAVEL RECEBE 1.
                                    system("pause");
                                    system("cls");;

                                }//PAREI AQUI........................................................30/11/2019 04:21.
                                break;
                            }
                            } while(escolha_carro!=2);//FIM LACO CADASTRA CARRO
                            system("pause");
                            system("cls");
                    } // FIM CASE 1 CLIENTE/CONSULTA
                    break;

                    case 2:{ // INICIO CASE 2 CLIENTE/CADASTRO
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO
                        arq_cliente = fopen("arquivo_cliente.txt", "a"); //ABRIR ARQUIVO CLIENTE | "A" SIGNIFICA.......
                        if(arq_cliente ==  NULL){ //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
                            printf("Erro na abertura do arquivo!"); //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
                        }
                        Cliente cli; //CRIANDO UMA VAREAVEL "CLI" DO TIPO DA STRUCT, CLIENTE.
                        cli = GetCliente(); //CHAMA FUNCAO PARA LER DADOS DO CLIENTE // RETORNAR DADOS PARA "CLI".
                        fprintf(arq_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //GRAVAR DADOS DA VAREAVEL "CLI" CLIENTE NO ARQUIVO CLIENTE
                        fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE
                        printf("Cliente Cadastrado com Sucesso\n\n"); //MENSAGEM DE CONCLUSSAO
                        int auxCli; //CRIANDO VAREAVEL AUXILIAR PARA GUARDAR ID DO CLIENTE.
                        auxCli = cli.idCli; //GUARDANDO ID DO CLIENTE NA VAREAVEL AUXILIAR.
                        system("pause");
                        system("cls");

                            int escolha_carro,cont=0;
                            char mensagemCar[10];
                            do
                            {
                            if( cont == 0){
                                strcpy(mensagemCar, "UM CARRO");
                            }else{
                                strcpy(mensagemCar, "OUTRO CARRO");
                            }cont++;
                            printf("|-------------------------------|\n");
                            printf("|        CADASTRAR CARRO        |\n");
                            printf("|-------------------------------|\n");
                            printf("|-------------------------------|\n");
                            printf("|  1  |          SIM            |\n");
                            printf("|-------------------------------|\n");
                            printf("|  2  |          NAO            |\n");
                            printf("|-------------------------------|\n");
                            printf("DESEJA CADASTRAR %s PARA ESTE CLIENTE?: ",mensagemCar);
                            scanf("%d",&escolha_carro);
                            system("cls");
                            switch(escolha_carro){
                                case 1:{
                                    printf("|-------------------------------|\n");
                                    printf("|        CADASTRAR CARRO        |\n");
                                    printf("|-------------------------------|\n");
                                    FILE *arq_carro;
                                    arq_carro = fopen("arquivo_carro.txt", "a"); //ABRIR ARQUIVO CARRO
                                    if(arq_carro ==  NULL){ //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CARRO
                                        printf("ERRO NA ABERTURA DO ARQUIVO!"); //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
                                        return 1;
                                    }
                                    Cliente cli;
                                    Carro car;
                                    car = GetCarro();
                                    car.idCli = auxCli;
                                    fprintf(arq_carro,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli); //GRAVAR DADOS DO "CAR" CARRO NO ARQUIVO CARRO
                                    fclose(arq_carro); //FECHAR ARQUIVO CARRO
                                    printf("Carro Cadastrado com Sucesso\n"); //MENSAGEM DE CONCLUSSAO
                                    system("pause");
                                    system("cls");;

                                }
                                break;
                            }
                            } while(escolha_carro!=2);
                    } // FIM CASE 2 CLIENTE CADASTRO
                    break;
                    case 3:{
                        printf("|-------------------------------|\n");
                        printf("|         LISTAR CLIENTE        |\n");
                        printf("|-------------------------------|\n");
						Cliente cli;
						FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO
						arq_cliente = fopen("arquivo_cliente.txt", "r");
						while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli)!= EOF){
                                    printf("NOME: %s\nCPF: %s\nENDERECO: %s\nID CLIENTE: %d\n=================================\n",cli.nome,cli.cpf,cli.endereco,cli.idCli);
						}
						fclose(arq_cliente);
						system("pause");
						system("cls");
                    } //FIM CASE 3 CLIENTE LISTA CLIENTE
                    break;
                    case 4:{
                        printf("|-------------------------------|\n");
                        printf("|         LISTAR CARRO          |\n");
                        printf("|-------------------------------|\n");
						Carro car;
						FILE *arq_carro;    //PONTEIRO PARA ARQUIVO
						arq_carro = fopen("arquivo_carro.txt", "r");
						while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli)!= EOF){
                            printf("MODELO: %s\nCOR: %s\nPLACA: %s\nID CARRO: %d\n=================================\n",car.modelo,car.cor,car.placa,car.idCar);
						}
						fclose(arq_carro);
						system("pause");
						system("cls");
                    } //FIM CASE 4 CLIENTE LISTA CARRO
                    break;
                    case 5:{
                        int excluirID;
                        printf("|-------------------------------|\n");
                        printf("|         EXCLUIR CLIENTE       |\n");
                        printf("|-------------------------------|\n");
                        printf("| DIGITE O ID DO CLIENTE PARA EXCLUIR: ");
                        scanf ("%d",&excluirID);
                        Cliente cli;
                        FILE *temp_cliente, *arq_cliente; //  ARQUIVO TEMPORARIO
						if((arq_cliente = fopen("arquivo_cliente.txt", "rb")) == NULL);
						if((temp_cliente = fopen("temp_cliente.txt","wb")) == NULL);

                        Carro car;
                        FILE *temp_carro, *arq_carro;
                        if((arq_carro = fopen("arquivo_carro.txt","rb")) == NULL);
                        if((temp_carro = fopen("temp_carro","wb")) == NULL);

						// PASSA TODOS OS REGISTROS DOS ARQUIVOS PARA OS ARQUIVOS TEMPORARIOS, EXCETO O REGISTRO COM O ID QUE SERA EXCLUIDO
                        while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli) != EOF){ //LISTANDO ARQUIVO_CLIENTE
                            if (excluirID != cli.idCli){ //CASO ID QUE DESEJA EXCLUIR SEJA DIFERENTE DO ID DO CLIENTE...
                                fprintf(temp_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //...PRINTAR DADOS CLIENTE NO ARQUIVO TEMP
                            }
                        }
                        while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli) != EOF){//LISTANDO ARQUIVO_CARRO
                            if(excluirID != car.idCli){
                                fprintf(temp_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,car.idCar,car.idCli);
                            }
                        }

                        /*   FECHAR ARQUIVOS ABERTOS     */
                        fclose(arq_cliente);
                        fclose(temp_cliente);
                        fclose(arq_carro);
                        fclose(temp_carro);

                        remove("arquivo_cliente.txt"); //EXCLUIR ARQUIVO_CLIENTE
                        rename("temp_cliente.txt", "arquivo_cliente.txt"); // RENOMEAR ARQUIVO TEMP_CLIENTE PARA ARQUIVO_CLIENTE
                        remove("arquivo_carro.txt"); //EXCLUIR ARQUIVO_CARRO
                        rename("temp_carro.txt", "arquivo_carro.txt"); // RENOMEAR ARQUIVO TEMP_CARRO PARA ARQUIVO_CARRO
                        printf("CLIENTE EXCLUIDO!");
                        system("pause");
                        system("cls");
                    }
                    break;
                    case 6:{
                        int excluirIDCAR;
                        printf("|-------------------------------|\n");
                        printf("|         EXCLUIR CARRO         |\n");
                        printf("|-------------------------------|\n");
                        printf("| DIGITE O ID DO CARRO PARA EXCLUIR: ");
                        scanf ("%d",&excluirIDCAR);
                        Carro car;
                        FILE *temp_car, *arq_carro; //  ARQUIVO TEMPORARIO
						if((arq_carro = fopen("arquivo_carro.txt", "rb")) == NULL);
						if((temp_car = fopen("temp_carro.txt","wb")) == NULL);
						// PASSA TODOS OS REGISTROS DO ARQUIVO CLIENTE PARA O ARQUIVO TEMP, EXCETO O REGISTRO COM O ID QUE SERA EXCLUIDO
                        while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli) != EOF){
                            if (excluirIDCAR != car.idCar){
                                fprintf(temp_car,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli);
                            }
                        }
                        fclose(arq_carro);
                        fclose(temp_car);
                        remove("arquivo_carro.txt"); //EXCLUIR ARQUIVO CLIENTE
                        rename("temp_carro.txt", "arquivo_carro.txt"); // RENOMEAR ARQUIVO TEMP PARA ARQUIVO CLIENTE
                        printf("\nCARRO EXCLUIDO!\n");
                        system("pause");
                        system("cls");
                    }
                    break;

                } //FIM SWITCH CLENTE
            } // FIM CASE 1 MENU/CLIENTE
            break;
            case 2:{ //INICIO CASO 2 MENU/SERVICO. SUBMENU SERVICO
                int escolha_servico;
                printf("|-------------------------------|\n");
				printf("|             SERVICO           |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
                printf("|  3  |     LISTAR SERVICO      |\n");
                printf("|-------------------------------|\n");
                printf("|  4  |     EXCLUIR SERVICO     |\n");
                printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&escolha_servico);
				system("cls");


            }//FIM CASE 2 MENU/SERVICO
            break;
            case 3:{ //INICIO CASO 3 MENU/FUNCIONARIO. SUBMENU FUNCIONARIO.
                int escolha_funcionario;
                printf("|-------------------------------|\n");
				printf("|           FUNCIONARIO         |\n");
				printf("|-------------------------------|\n");
				printf("|-------------------------------|\n");
				printf("|  1  |       CONSULTA          |\n");
				printf("|-------------------------------|\n");
				printf("|  2  |       CADASTRAR         |\n");
				printf("|-------------------------------|\n");
                printf("|  3  |   LISTAR FUNCIONARIO    |\n");
                printf("|-------------------------------|\n");
                printf("|  4  |   EXCLUIR FUNCIONARIO   |\n");
                printf("|-------------------------------|\n");
				printf("| Escolha uma opcao: ");
				scanf("%d",&escolha_funcionario);
				system("cls");
				switch(escolha_funcionario){ //INICIO SUBMENU FUNCIONARIO.
                    case 1:{// INICIO CASE 1 SUBMENU FUNCIONARIO/CONSULTA.
                        int consultaIDFUN;
                        printf("|-------------------------------|\n");
                        printf("|            CONSULTA           |\n");
                        printf("|-------------------------------|\n");
                        printf("| Digite o ID do Funcionario: ");
                        scanf ("%d",&consultaIDFUN);
                        int confirmaSeFuncionarioExiste = 0; //SE 0 == CLIENTE NAO EXISTE  |  SE 1 == CLIENTE EXISTE.
						Funcionario fun;
						Servico serv;
						int auxIDFun; // AUXILIAR PARA GUARDA ID DO CLIENTE QUE FOI CONSULTADO.

						FILE *arq_funcionario;    //PONTEIRO PARA ARQUIVO.
						arq_funcionario = fopen("arquivo_funcionario.txt", "r"); //ABRIR ARQUIVO CLIENTE.
						while(fscanf(arq_funcionario,"%s %s %s %d",fun.nome,fun.cpf,fun.endereco,&fun.idFun)!= EOF){ //LACO PARA LER TODAS AS LINHAS DO ARQUIVO
                            if(consultaIDFUN == fun.idFun){//CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                printf("\n=== DADOS FUNCIONARIO ===\nNOME: %s\nCPF: %s\nENDERECO: %s\nID FUNCIONARIO: %d\n",fun.nome,fun.cpf,fun.endereco,fun.idFun); //RETORNA OS DADOS DO CLIENTE DESEJADO
                                confirmaSeFuncionarioExiste = 1; //SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CLIENTE EXISTE, VAREAVEL RECEBE 1.
                                auxIDFun = fun.idFun; //GUARDANDO O ID DO CLIENTE CONSULTADO NA VAREAVEL AUXILIAR.
                            } //FIM DA CONDICIONAL
						}// FIM DO LACO.
						if(confirmaSeFuncionarioExiste == 0){//SO ENTRA NESSA CONDICAO CASO O CLIENTE NAO EXISTA, VALOR DA VAREAVEL == 0.
                                printf("\nFUNCIONARIO NAO ENCONTRADO\n");// PRINTA MENSAGEM
                                system("pause");
                                system("cls");
                                break;//ENCERRA A CONTINUACAO DO PROGRAMA E VOLTA PARA O MENUR PRINCIPAL.
                        }
                        system("pause");
                        system("cls");
                        /*int confirmaSeCarroExiste = 0;// SE O == CARRO NÃO EXISTE  |  SE 1 == CARRO EXISTE.
                        int numerosCarros = 1;//VAREAVEL PARA CONTAR O NUMEROS DE CARROS DO CLIENTE, INICIALMENTE RECEBE 1.
						FILE *arq_carro; // PONTEIRO PARA ARQUIVO CARRO
						arq_carro = fopen("arquivo_carro.txt", "r"); // ABRIR ARQUIVO CARRO
						if (confirmaSeClienteExiste == 1){//CONDICIONAL PARA PERMITIR CADASTRAR UM CARRO APENAS SE EXISTIR UM CLIENTE DONO DESTE CARRO, PARA NÃO PERMITIR QUE SEJA CADASTRADO UM CARRO SEM UM CLIENTE ASSOCIADO A ELE.
                            while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli)!= EOF){ //LER TODAS AS LINHAS DO ARQUIVO
                                if(consultaID == car.idCli){//CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO, CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                    printf("\n=== DADOS DO CARRO %d ===\nMODELO: %s\nCOR: %s\nPLACA: %s\nID CARRO: %d\n",numerosCarros,car.modelo,car.cor,car.placa,car.idCar); //RETORNA OS DADOS
                                    numerosCarros++;//INCREMENTA NUMEROS DE CARROS CADASTRADOS.
                                    confirmaSeCarroExiste = 1;//SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CARRO EXISTE, VAREAVEL RECEBE 1.
                                }//FIM DA CONDICIONAL
                            }//FIM DO LACO
                            if(confirmaSeCarroExiste == 0){//SO ENTRA NESSA CONDICAO CASO CARRO NAO EXISTA, VALOR DA VAREAVEL == 0.
                                printf("\nCLIENTE NAO TEM CARRO CADASTRADO\n");//PRINTA MENSAGEM.
                            }
						}
						fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE.
						fclose(arq_carro);  //FECHAR ARQUIVO CARRO.
						system("pause");
						system("cls");*/

                    } //FIM CASE 1 SUBMENU FUNCIONARIO/CONSULTA.
                    break;
                    case 2:{//INICIO CASE 2 SUBMENU FUNCIONARAIO/CADASTRO.
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *arq_funcionario;    //PONTEIRO PARA ARQUIVO
                        arq_funcionario = fopen("arquivo_funcionario.txt", "a"); //ABRIR ARQUIVO CLIENTE | "A" SIGNIFICA.......
                        if(arq_funcionario ==  NULL){ //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
                            printf("Erro na abertura do arquivo!"); //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
                        }
                        Funcionario fun; //CRIANDO UMA VAREAVEL "CLI" DO TIPO DA STRUCT, CLIENTE.
                        fun = Getfuncionario(); //CHAMA FUNCAO PARA LER DADOS DO CLIENTE // RETORNAR DADOS PARA "CLI".
                        fprintf(arq_funcionario,"%s %s %s %d\n",fun.nome,fun.cpf,fun.endereco,fun.idFun); //GRAVAR DADOS DA VAREAVEL "CLI" CLIENTE NO ARQUIVO CLIENTE
                        fclose(arq_funcionario); //FECHAR ARQUIVO CLIENTE
                        printf("Funcionario Cadastrado com Sucesso\n\n"); //MENSAGEM DE CONCLUSSAO
                        system("pause");
                        system("cls");
                    } //FIM CASE 2 SUBMENU FUNCIONARIO/CADASTRO.
                    break;
                    case 3:{//INICIO CASE 3 SUBMENU FUNCIONARIO/LISTAR FUNCIONARIO.
                        printf("|-------------------------------|\n");
                        printf("|      LISTAR FUNCIONARIO       |\n");
                        printf("|-------------------------------|\n");
						Funcionario fun;
						FILE *arq_funcionario;    //PONTEIRO PARA ARQUIVO
						arq_funcionario = fopen("arquivo_funcionario.txt", "r");
						while(fscanf(arq_funcionario,"%s %s %s %d",fun.nome,fun.cpf,fun.endereco,&fun.idFun)!= EOF){
                            printf("NOME: %s\nCPF: %s\nENDERECO: %s\nID FUNCIONARIO: %d\n=================================\n",fun.nome,fun.cpf,fun.endereco,fun.idFun);
						}
						fclose(arq_funcionario);
						system("pause");
						system("cls");
                    } //FIM CASE 3 SUBMENU FUNCIONARIO/LISTAR FINCIONARIO.
                    break;
                    case 4:{// INICIO CASE 4 SUBMENU FUNCIONARIO/EXCLUIR FUNCIONARIO.
                        int excluirIDCAR;
                        printf("|-------------------------------|\n");
                        printf("|      EXCLUIR FUNCINARIO       |\n");
                        printf("|-------------------------------|\n");
                        printf("| DIGITE O ID DO FUNCIONARIO PARA EXCLUIR: ");
                        scanf ("%d",&excluirIDFUN);
                        Funcionario fun;
                        FILE *temp_fun, *arq_funcionario; //  ARQUIVO TEMPORARIO
						if((arq_funcionario = fopen("arquivo_funcionario.txt", "rb")) == NULL);
						if((temp_fun = fopen("temp_funcionario.txt","wb")) == NULL);
						// PASSA TODOS OS REGISTROS DO ARQUIVO CLIENTE PARA O ARQUIVO TEMP, EXCETO O REGISTRO COM O ID QUE SERA EXCLUIDO
                        while(fscanf(arq_funcionario,"%s %s %s %d",fun.nome,fun.cpf,fun.endereco,&fun.idFun) != EOF){
                            if (excluirIDFUN != fun.idFun){
                                fprintf(temp_fun,"%s %s %s %d\n",fun.nome,fun.cpf,fun.endereco,fun.idFun);
                            }
                        }
                        fclose(arq_funcionario);
                        fclose(temp_fun);
                        remove("arquivo_funcionario.txt"); //EXCLUIR ARQUIVO CLIENTE
                        rename("temp_funcionario.txt", "arquivo_funcionario.txt"); // RENOMEAR ARQUIVO TEMP PARA ARQUIVO CLIENTE
                        printf("\nFUNCIONARIO EXCLUIDO!\n");
                        system("pause");
                        system("cls");
                    }// FIM CASE 4 SUBMENU FUNCIONARIO/EXCLUIR FUNCIONARIO.
                    break;
				}// FIM SWITCH SUBMENU FUNCIONARIO.
            }// FIM CASE 3 MENU/FUNCIONARIO.
            break;
        } //FIM SWITCH MENU
    } while(opcao!=4);// FIM DO LACO DO MENU.
}//FIM MENU

/*INICIO*/
int main(){
    menu();
    printf("FIM");
}

