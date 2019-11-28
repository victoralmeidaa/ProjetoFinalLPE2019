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
    printf("MODEL: ");
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
                        int err = 0;
						Cliente cli;
						Carro car;
						int z;
						FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO
						arq_cliente = fopen("arquivo_cliente.txt", "r"); //ABRIR ARQUIVO CLIENTE
						while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli)!= EOF){ //LER TODAS AS LINHAS DO ARQUIVO
                            if(consultaID == cli.idCli){    //COMPARAR OS IDs CADASTRADOS NO ARQUIVO CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                printf("\n=== DADOS CLIENTE ===\nNOME: %s\nCPF: %s\nENDERECO: %s\nID CLIENTE: %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //RETORNA OS DADOS
                                err = 1;
                                z = cli.idCli;
                            }
						}
						if(err == 0){
                                printf("\nCLIENTE NAO ENCONTRADO\n");
                        }
                        int errc = 0;int nc=0;
						FILE *arq_carro;
						arq_carro = fopen("arquivo_carro.txt", "r");
						if (err == 1){
                            while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli)!= EOF){ //LER TODAS AS LINHAS DO ARQUIVO
                                if(consultaID == car.idCli){    //COMPARAR OS IDs CADASTRADOS NO ARQUIVO CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
                                    nc++;
                                    printf("\n=== DADOS DO CARRO %d ===\nMODELO: %s\nCOR: %s\nPLACA: %s\nID CARRO: %d\n",nc,car.modelo,car.cor,car.placa,car.idCar); //RETORNA OS DADOS
                                    errc = 1;
                                }
                            }
                            if(errc == 0){
                                printf("\nCLIENTE NAO TEM CARRO CADASTRADO\n");
                            }
						}
						fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE
						fclose(arq_carro);
						system("pause");
						system("cls");

						int escolha_carro;
                            do
                            {
                            printf("|-------------------------------|\n");
                            printf("|        CADASTRAR CARRO        |\n");
                            printf("|-------------------------------|\n");
                            printf("|-------------------------------|\n");
                            printf("|  1  |          SIM            |\n");
                            printf("|-------------------------------|\n");
                            printf("|  2  |          NAO            |\n");
                            printf("|-------------------------------|\n");
                            printf("DESEJA CADASTRAR UM NOVO CARRO PARA ESTE CLIENTE?: ");
                            scanf("%d",&escolha_carro);
                            //system("cls");
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
                                    Carro car;
                                    car = GetCarro();
                                    car.idCli = z;
                                    fprintf(arq_carro,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli); //GRAVAR DADOS DO "CAR" CARRO NO ARQUIVO CARRO
                                    fclose(arq_carro); //FECHAR ARQUIVO CARRO
                                    printf("Carro Cadastrado com Sucesso\n"); //MENSAGEM DE CONCLUSSAO
                                    system("pause");
                                    system("cls");;

                                }
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

                            int escolha_carro;
                            do
                            {
                            printf("|-------------------------------|\n");
                            printf("|        CADASTRAR CARRO        |\n");
                            printf("|-------------------------------|\n");
                            printf("|-------------------------------|\n");
                            printf("|  1  |          SIM            |\n");
                            printf("|-------------------------------|\n");
                            printf("|  2  |          NAO            |\n");
                            printf("|-------------------------------|\n");
                            printf("DESEJA CADASTRAR CARRO?: ");
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
                        FILE *temp, *arq_cliente; //  ARQUIVO TEMPORARIO
						if((arq_cliente = fopen("arquivo_cliente.txt", "rb")) == NULL);
						if((temp = fopen("temp.txt","wb")) == NULL);
// ABRIR ARQUIVO CARRO E CRIAR ARQUIVO TEMPcARRO;
						// PASSA TODOS OS REGISTROS DO ARQUIVO CLIENTE PARA O ARQUIVO TEMP, EXCETO O REGISTRO COM O ID QUE SERA EXCLUIDO
                        while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli) != EOF){
                            if (excluirID != cli.idCli){
                                fprintf(temp,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli);
                            }
                        }
                        fclose(arq_cliente);
                        fclose(temp);
                        remove("arquivo_cliente.txt"); //EXCLUIR ARQUIVO CLIENTE
                        rename("temp.txt", "arquivo_cliente.txt"); // RENOMEAR ARQUIVO TEMP PARA ARQUIVO CLIENTE
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

