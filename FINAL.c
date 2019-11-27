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
    gets(&cli.nome);
    printf("CPF: ");
    gets(&cli.cpf);
    printf("ENDERECO: ");
    gets(&cli.endereco);
    printf("ID: ");
    scanf("%d",&cli.idCli);
    return cli;
}

Carro GetCarro(){ //FUNCAO PARA LER DADOS DE CARROS
    Carro car;
    Cliente cli;
    printf("MODEL: ");
    gets(&car.modelo);
    printf("COR: ");
    gets(&car.cor);
    printf("PLACA: ");
    gets(&car.placa);
    printf("ID CARRO:");
    scanf("%d",&car.idCar);
    car.idCli = cli.idCli;
    return car;
}

Funcionario Getfuncionario(){ //FUNCAO PARA LER DADOS DE CARROS
    Funcionario fun;
    printf("NOME: ");
    gets(&fun.nome);
    printf("CPF: ");
    gets(&fun.cpf);
    printf("ENDERECO: ");
    gets(&fun.endereco);
    printf("ID: ");
    scanf("%d",&fun.idFun);
}

Servico GetServico(){ //FUNCAO PARA LER DADOS DE CARROS
    Servico serv;
    printf("TITULO: ");
    gets(&serv.titulo);
    printf("DESCRICAO: ");
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
				printf("|  3  |        LISTAR           |\n");
				printf("|-------------------------------|\n");
				printf("|  4  |        EXCLUIR          |\n");
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
						Cliente cli;
						FILE *arq_cliente;    //PONTEIRO PARA ARQUIVO
						arq_cliente = fopen("arquivo_cliente.txt", "r"); //ABRIR ARQUIVO CLIENTE
						while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli)!= EOF){
                            if(consultaID == cli.idCli){
                                    printf("NOME: %s\nCPF: %s\nENDERECO: %s\nID: %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli);
                            }
						}
						fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE
						system("pause");
						system("cls");
                    }
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
                        cli = GetCliente(); //CHAMA FUNCAO PARA LER DADOS DO CLIENTE
                        fprintf(arq_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //GRAVAR DADOS DO CLIENTE NO ARQUIVO CLIENTE
                        fclose(arq_cliente); //FECHAR ARQUIVO CLIENTE
                        printf("Cliente Cadastrado com Sucesso\n"); //MENSAGEM CONCLUSSAO
                        system("pause");
                        system("cls");
                    }
                    break;


    } while(opcao!=4);
}

/*INICIO*/
int main(){
    menu();
    printf("FIM");
}
