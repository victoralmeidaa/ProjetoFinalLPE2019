#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 /* ESTRUTURAS */
typedef struct Cliente{ //ESTRUTURA CLIENTE
    char nome[50];
    char cpf[10];
    char endereco[50];
    int idCli;
}
Cliente;

typedef struct Carro{ //ESTRUTURA CARRO
    char modelo[20];
    char cor[20];
    char placa[10];
    int idCar;
    int idCli;
}
Carro;

typedef struct Funcionario{ //ESTRUTURA FUNCINARIO
    char nome[20];
    char cpf[10];
    char endereco[50];
    int idFun;
}
Funcionario;

typedef struct Servico{ //ESTRUTURA SERVICO
    char titulo[20];
    char descricao[50];
    int idServ;
    int idFun;
    int idCar;
}
Servico;

/* FUNÇÓES */
Cliente GetCliente(){ //FUNCAO PARA LER DADOS DO CLIENTES
    Cliente cli;
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
    return cli;
}

Carro GetCarro(){ //FUNCAO PARA LER DADOS DE CARROS
    Carro car;
    Cliente cli;
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
    return car;
}

Funcionario Getfuncionario(){ //FUNCAO PARA LER DADOS DE CARROS
    Funcionario fun;
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
}

Servico GetServico(){ //FUNCAO PARA LER DADOS DE CARROS
    Servico serv;
    printf("TITULO: ");
    setbuf(stdin,NULL);
    gets(&serv.titulo);
    printf("DESCRICAO: ");
    setbuf(stdin,NULL);
    gets(&serv.descricao);
    printf("ID SERVICO: ");
    scanf("%d",&serv.idServ);

}

/*   FUNCAO MENU    */
void menu(){
    int opcao;
    do
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

        switch(opcao){
            case 1:{
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
                            char mensagemCar[20];
                            do
                            {
                            if(confirmaSeCarroExiste == 0){//SE O CLIENTE NÃO TIVER CARRO CADASTRADO A MENNSAGEM SERA "UM CARRO".
                                strcpy(mensagemCar, "UM CARRO");//FUNCAO PARA COPIAR "STRING"(MESAGEM) PARA DENTRO DA VAREAVEL
                            }else{// SE O CLIENTE TIVER UM CARRO CADASTRADO A MENSAGEM SERA "UM NOVO CARRO".
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
                            printf("DESEJA CADASTRAR %s PARA ESTE CLIENTE?: ",mensagemCar);//COLOCA A MENSAGEM ENTRE A PALAVRA
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
                            } while(escolha_carro!=2);
						system("pause");
						system("cls");
                    } // FIM CASE 1 CLIENTE CONSULTA
                    break;

                    case 2:{
                        printf("|-------------------------------|\n");
                        printf("|  2  |       CADASTRAR         |\n");
                        printf("|-------------------------------|\n");
                        FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO
                        arq_cliente = fopen("arquivo_cliente.txt", "a"); //ABRIR ARQUIVO CLIENTE
                        if(arq_cliente ==  NULL){ //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
                            printf("Erro na abertura do arquivo!"); //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
                            return 1;
                        }
                        Cliente cli;
                        cli = GetCliente(); //CHAMA FUNCAO PARA LER DADOS DO CLIENTE // RETORNAR DADOS PARA "CLI"
                        fprintf(arq_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //GRAVAR DADOS DO "CLI" CLIENTE NO ARQUIVO CLIENTE
                        fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE
                        printf("Cliente Cadastrado com Sucesso\n\n"); //MENSAGEM DE CONCLUSSAO
                        int x;
                        x = cli.idCli;
                        system("pause");
                        system("cls");

                            int escolha_carro,cont=0;
                            char ncar[10];
                            do
                            {
                            if( cont == 0){
                                strcpy(ncar, "UM");
                            }else{
                                strcpy(ncar, "OUTRO");
                            }cont++;
                            printf("|-------------------------------|\n");
                            printf("|        CADASTRAR CARRO        |\n");
                            printf("|-------------------------------|\n");
                            printf("|-------------------------------|\n");
                            printf("|  1  |          SIM            |\n");
                            printf("|-------------------------------|\n");
                            printf("|  2  |          NAO            |\n");
                            printf("|-------------------------------|\n");
                            printf("DESEJA CADASTRAR %s CARRO PARA ESTE CLIENTE?: ",ncar);
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
                                    car.idCli = x;
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


        } //FIM SWITCH MENU
    } while(opcao!=4);// FIM DO WHILE
}//FIM MENU

/*INICIO*/
int main(){
    menu();
    printf("FIM");
}

