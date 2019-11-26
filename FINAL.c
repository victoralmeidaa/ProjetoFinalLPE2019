#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

 /* ESTRUTURAS */
typedef struct Cliente{ //ESTRUTURA CLIENTE
    char nome[50];
    char endereco[50];
    char cpf[10];
    int idCli;
}
Cliente;

typedef struct Carro{ //ESTRUTURA CARRO
    char modelo[20];
    char cor[20];
    char placa[10];
    int idCar;
}

typedef struct Servico{ //ESTRUTURA SERVIÇO
    char titulo[20];
    char descricao[50];
    int idServ;
}

typedef struct Funcionario{ //ESTRUTURA FUNCINARIO
    char nome[20];
    char cpf[10];
    char endereco[50];
    int idFun;
}

int main(){

}
