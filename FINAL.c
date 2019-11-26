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
        printf("|  2  |       SERVIÇO           |\n");
        printf("|-------------------------------|\n");
        printf("|  3  |       FUNCIONARIOS      |\n");
        printf("|-------------------------------|\n");
        printf("|  4  |       SAIR              |\n");
        printf("|-------------------------------|\n");
        printf("| Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

    } while(opcao!=4);
}

int main(){
    Cliente cli;
    cli = GetCliente();

}
