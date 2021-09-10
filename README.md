# Sistema de Genstão Lavajato em C
## Projeto Final - Linguagem de Programação Estruturada 2019.2
### Funções 

<!--ts-->
   * [Criar](#Criar)
      - [x] [Cliente](#Cliente)
      - Estrutura de dados do cliente.
      - Função para ler dados do cliente.
      - Gravar dados do cliente no arquivo txt. 
        - ↳ : Logo após cadastrar o cliente o sistema pede para que seja cadastrado o veículo associado a este cliente.
      
      - [x] [Carro](#Carro)
      - Estrutura de dados de carro.
      - Função para ler dados do carro.
      - Gravar dados do carro no arquivo txt.
     
  
      - [x] [Funcionario](#funcionario)
      - Estrutura de dados do funcionario.
      - Função para çer dados do funcionario.
      - gravar dados do funcionario no arquivo txt.
     
      - [x] [Serviço](#serviço)
      - Estrutura de dados do serviço.
      - Função para ler dados do serviço.
      - Gravar dados do serviço no arquivi txt.
      
   * [Consultar](#Consultar)
      - [x] [Consulta de Cliente](#consultar-cliente)
      
      - [x] [Consulta de Funcionario](#consultar-funcionario)

      - [x] [Consulta de Serviço](#consultar-serviço)
       
   * [Listar](#Listar)
      - [x] [Listar Cliente(s)](#listar-cliente)
      
      - [x] [Listar Funcionario(s)](#listar-funcionario)

      - [x] [Listar Serviço(s)](#listar-serviço)

   * [Excluir](#Excluir)
      - [x] [Excluir Cliente](#excluir-cliente)
      
      - [x] [Excluir Funcionario](#excluir-funcionario)
      
      - [x] [Excluir Serviço](#excluir-serviço)

<!--te-->
##


# CRIAR
Cliente
===========
- ESTRUTURA CLIENTE
```bash
typedef struct Cliente{                 	    //ESTRUTURA DO TIPO CLIENTE
    char nome[50];				    //NOME
    char cpf[10];				    //CPF
    char endereco[50];                              //ENDERECO
    int idCli;                                      //ID CLIENTE
}
Cliente;

```

- FUNÇÃO LER DADOS CLIENTE
```bash
Cliente GetCliente(){                               //FUNCAO DO TIPO CLIENTE PARA LER DADOS DO CLIENTES
     Cliente cli;                                   //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CLIENTE.
     printf("NOME: ");
     setbuf(stdin,NULL);
     gets(&cli.nome);				    //LER NOME CLIENTE.

     int len;					    //VAREAVEL DE TIPO INT, SERVE PARA GUARDA A QUANTIDADE DE CARACTERES DIGITADO EM LER CPF
     int i,cond;
     
     do{                                            //INICIO "DO WHILE"
         cond=0;
         printf("DIGITE CPF COM 11 DIGITOS: ");            
         setbuf(stdin,NULL);
         gets(&cli.cpf);			    //LER CPF CLIENTE
	 len = strlen(cli.cpf);			    //GUARDA A QUANTIDADE DE CARACTERES INFORMADOS EM "CLI.CPF"
	 if (len == 11){				    
     	    for(i=0; i<len; i++){                   //LAÇO PARA LER TODOS OS 11 CARACTERES DE "CLI.CPF"
              if(!isdigit(cli.cpf[i])){		    //FUNCAO "ISDIGIT()" VERIFICA SE O VALOR PASSADO E UM INT OU STRING
                 cond = 1;
              }
            }
	  }else{
            printf("\nQUANTIDADE DE NUMEROS INVALIDA!\n");
	  }
          if(cond == 1){
            printf("\nINVALIDO, DIGITE APENAS NUMEROS\n");
          }
     }while(len != 11  || cond != 0);               //FIM "DO WHILE"

     printf("ENDERECO: ");				    
     setbuf(stdin,NULL);    				    
     gets(&cli.endereco); 			    //LER ENDERECO DO CLIENTE
     printf("ID: ");				    
     scanf("%d",&cli.idCli);		            //LER ID DO CLIENTE
     return cli;                                    //FUNCAO RETORNA ESTRUTURA DO TIPO CLIENTE.
}
```



- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO.TXT
```bash
FILE *arq_cliente;                                  //PONTEIRO PARA ARQUIVO
arq_cliente = fopen("arquivo_cliente.txt", "a");    //ABRIR ARQUIVO CLIENTE | "A" ABRE O ARQUIVO PARA GRAVAÇÃO.
if(arq_cliente ==  NULL){                           //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
    printf("Erro na abertura do arquivo!");         //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
}
Cliente cli;                                        //CRIANDO UMA VAREAVEL "CLI" DO TIPO DA STRUCT, CLIENTE.
cli = GetCliente();                                 //CHAMA FUNCAO PARA LER DADOS DO CLIENTE // RETORNAR DADOS PARA "CLI".

fprintf(arq_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //GRAVAR DADOS DA VAREAVEL "CLI" CLIENTE NO ARQUIVO CLIENTE
fclose(arq_cliente);                                //FECHAR ARQUIVO CLIENTE
printf("Cliente Cadastrado com Sucesso\n\n");       //MENSAGEM DE CONCLUSSAO
int auxCli;                                         //CRIANDO VAREAVEL AUXILIAR PARA GUARDAR ID DO CLIENTE.
auxCli = cli.idCli;                                 //GUARDANDO ID DO CLIENTE NA VAREAVEL AUXILIAR.
system("pause");
system("cls");
```


Carro
===========
- ESTRUTURA CARRO
```bash
typedef struct Carro{                               //ESTRUTURA DO TIPO CARRO
    char modelo[20];                                //MODELO 
    char cor[20];                                   //COR
    char placa[10];                                 //PLACA
    int idCar;                                      //ID CARRO
    int idCli;                                      //ID CLIENTE
}
Carro;
```

- FUNÇÃO LER DADOS CARRO
```bash
Carro GetCarro(){ 				    //FUNCAO DO TIPO CARRO PARA LER DADOS DE CARROS.
    Carro car;					    //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CARRO.
    printf("MODELO: ");
    setbuf(stdin,NULL);                             
    gets(&car.modelo);                              //LER MODELO CARRO
    printf("COR: ");
    setbuf(stdin,NULL);
    gets(&car.cor);                                 //LER COR CARRO
    printf("PLACA: ");
    setbuf(stdin,NULL);
    gets(&car.placa);                               //LER PLACA CARRO
    printf("ID CARRO:");
    scanf("%d",&car.idCar);                         //LER ID CARRO
    return car;                                     //FUNCAO RETORNA ESTRUTURA DO TIPO CARRO.
}
```

- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO TXT.
```bash
FILE *arq_carro;
arq_carro = fopen("arquivo_carro.txt", "a");        //ABRIR ARQUIVO CARRO. | "A" ABRE O ARQUIVO PARA GRAVAÇÃO.
if(arq_carro ==  NULL){                             //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CARRO
    printf("ERRO NA ABERTURA DO ARQUIVO!");         //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
    return 1;
}
Cliente cli;                                      
Carro car;                                          //CRIANDO UMA VAREAVEL "CAR" DO TIPO STRUCT, CARRO.
car = GetCarro();                                   //CHAMA FUNCAO PARA LER DADOS DO CARRO // RETORNAR DADOS PARA "CAR"
car.idCli = auxCli;                                 //COPIANDO VAREAVEL AUXILIAR COM O ID DO CLIENTE PARA ID DO CARRO
fprintf(arq_carro,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli); //GRAVAR DADOS DO "CAR" CARRO NO ARQUIVO CARRO
fclose(arq_carro);                                  //FECHAR ARQUIVO CARRO
printf("Carro Cadastrado com Sucesso\n");           //MENSAGEM DE CONCLUSSAO
system("pause");
system("cls");;
```

Funcionario
===========
- ESTRUTURA FUNCIONARIO
```bash
typedef struct Funcionario{                         //ESTRUTURA DO TIPO FUNCINARIO
    char nome[20];                                  //NOME
    char cpf[10];                                   //CPF
    char endereco[50];                              //ENDEREÇO
    int idFun;                                      //ID FUNCIONARIO
}
Funcionario;
```
- FUNÇÃO LER DADOS
```bash
Funcionario Getfuncionario(){                       //FUNCAO DO TIPO FUNCIONARIO PARA LER DADOS DE CARROS
    Funcionario fun;                                //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO FUNCIONARIO.
    printf("NOME: ");
    setbuf(stdin,NULL);
    gets(&fun.nome);                                //LER NOME FUNCIONARIO
    printf("CPF: ");
    setbuf(stdin,NULL);       
    gets(&fun.cpf);                                 //LER CPF FUNCIONARIO
    printf("ENDERECO: ");
    setbuf(stdin,NULL);
    gets(&fun.endereco);                            //LER ENDEREÇO FUNCIONARIO
    printf("ID: ");
    scanf("%d",&fun.idFun);                         //LER ID FUNCIONARIO
    return fun;                                     //FUNCAO RETORNA ESTRUTURA DO TIPO FUNCIONARIO.
}
```
- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO TXT.
```bash

```

Serviço
===========
- ESTRUTURA SERVIÇO
```bash
typedef struct Servico{                              //ESTRUTURA DO TIPO SERVICO
    char titulo[20];                                 //TITULO
    char preco[50];                                  //PREÇO
    int idServ;                                      //ID SERVIÇO
    int idFun;                                       //ID FUNCIONARIO
    int idCar;                                       //ID CARRO
}
Servico;
```
- FUNÇÃO LER DADOS
```bash 
Servico GetServico(){                                //FUNCAO PARA LER DADOS DE CARROS
    Servico serv;                                    //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO SERVICO.
    printf("TITULO: ");
    setbuf(stdin,NULL);
    gets(&serv.titulo);                              //LER TITULO SERVIÇO
    printf("PRECO: ");
    setbuf(stdin,NULL);
    gets(&serv.preco);                               //LER PREÇO
    printf("ID SERVICO: ");
    scanf("%d",&serv.idServ);                        //LER ID SERVIÇO
    return serv;                                     //FUNCAO RETORNA ESTRUTURA DO TIPO SERVICO.
}
```
- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO TXT.
```bash
printf("| Digite o ID do Cliente: ");               //PEDINDO O ID DO CLIENTE PARA CONSULTAR SE EXISTE NO SISTEMA.
scanf ("%d",&consultaID);                           //LER ID INFORMADO PELO USUARIO
int confirmaSeClienteExiste = 0;                    //VAREAVEL DE CONFIRMAÇÃO CLIENTE   SE 0 == CLIENTE NAO EXISTE  |  SE 1 == CLIENTE EXISTE.
Cliente cli;                                        //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CLIENTE.

int auxIDCli;                                       //CRIANDO AUXILIAR PARA GUARDA ID DO CLIENTE CONSULTADO.
FILE *arq_cliente;                                  //PONTEIRO PARA ARQUIVO.
arq_cliente = fopen("arquivo_cliente.txt", "r");    //ABRIR ARQUIVO CLIENTE. | "R" ABRE ARQUIVO PARA LEITURA.
while(fscanf(arq_cliente,"%s %s %s %d",cli.nome,cli.cpf,cli.endereco,&cli.idCli)!= EOF){                 //LACO PARA LER TODAS AS LINHAS DO ARQUIVO.
 if(consultaID == cli.idCli){                       //CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
  printf("\n=== DADOS CLIENTE ===\nNOME: %s\nCPF: %s\nENDERECO: %s\nID CLIENTE: %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //RETORNA OS DADOS DO CLIENTE DESEJADO
  confirmaSeClienteExiste = 1;                      //SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CLIENTE EXISTE, VAREAVEL DE CONFIRMAÇÃO CLIENTE RECEBE 1.
  auxIDCli = cli.idCli;                             //GUARDANDO O ID DO CLIENTE CONSULTADO NA VAREAVEL AUXILIAR.
 }                                                  //FIM DA CONDICIONAL
}                                                   //FIM DO LAÇO.
if(confirmaSeClienteExiste == 0){                   //SO ENTRA NESSA CONDICAO CASO O CLIENTE NAO EXISTA, VALOR DA VAREAVEL DE COMFIRMAÇÃO CLIENTE == 0. 
  printf("\nCLIENTE NAO ENCONTRADO\n");             //PRINTA MENSAGEM CLIENTE NÃO ENCONTRADO.
  system("pause");
  system("cls");
  break;                                            //ENCERRA A CONTINUACAO DO PROGRAMA E VOLTA PARA O MENUR PRINCIPAL.
}

int confirmaSeCarroExiste = 0;                      //VAREAVEL DE CONFIRMAÇÃO CARRO   SE O == CARRO NÃO EXISTE  |  SE 1 == CARRO EXISTE.
int numerosCarros = 1;                              //VAREAVEL PARA CONTAR O NUMEROS DE CARROS DO CLIENTE, INICIALMENTE RECEBE 1.
Carro car;                                          //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CARRO

FILE *arq_carro;                                    //PONTEIRO PARA ARQUIVO CARRO
arq_carro = fopen("arquivo_carro.txt", "r");        //ABRIR ARQUIVO CARRO. | "R" ABRE ARQUIVO PARA LEITURA.
if (confirmaSeClienteExiste == 1){                  //CONDICIONAL PERMITIR CADASTRAR CARRO APENAS SE EXISTIR UM CLIENTE PROPRIETARIO.
  while(fscanf(arq_carro,"%s %s %s %d %d",car.modelo,car.cor,car.placa,&car.idCar,&car.idCli)!= EOF){ //LER TODAS AS LINHAS DO ARQUIVO.
    if(consultaID == car.idCli){                    //CONDICIONAL PARA COMPARAR OS IDs CADASTRADOS NO ARQUIVO, CASO ENCONTRE O ID DESEJADO RETORNA OS DADOS ASSOCIADOS
      printf("\n=== DADOS DO CARRO %d ===\nMODELO: %s\nCOR: %s\nPLACA: %s\nID CARRO: %d\n",numerosCarros,car.modelo,car.cor,car.placa,car.idCar); //RETORNA OS DADOS
      numerosCarros++;                              //INCREMENTA NUMEROS DE CARROS CADASTRADOS.
      confirmaSeCarroExiste = 1;                    //SE ENTROU NA CONDICIONAL SIGNIFICA QUE O CARRO EXISTE, VAREAVEL DE CONFIRMAÇÃO CARRO RECEBE 1.
    }                                               //FIM DA CONDICIONAL
  }                                                 //FIM DO LAÇO
  if(confirmaSeCarroExiste == 0){                   //SO ENTRA NESSA CONDICAO CASO CARRO NAO EXISTA, VALOR DA VAREAVEL DE CONFIRMAÇÃO CARRO == 0.
    printf("\nCLIENTE NAO TEM CARRO CADASTRADO\n"); //PRINTA MENSAGEM CARRO NÃO CADASTRADO.
    system("pause");
    system("cls");
    fclose(arq_cliente);                            //FECHAR ARQUIVO CLIENTE.
    fclose(arq_carro);                              //FECHAR ARQUIVO CARRO.
    break;                                          //ENCERRA A CONTINUACAO DO PROGRAMA E VOLTA PARA O MENUR PRINCIPAL.
  }
}
fclose(arq_cliente);                                //FECHAR ARQUIVO CLIENTE.
fclose(arq_carro);                                  //FECHAR ARQUIVO CARRO.
						
printf("\nCRIAR SERVICO\n");
FILE *arq_servico;                                  //PONTEIRO PARA ARQUIVO SERVIÇO
arq_servico = fopen("arquivo_servico.txt", "a");    //ABRIR ARQUIVO CLIENTE | "A" ABRE ARQUIVO PARA GRAVAÇÃO
if(arq_servico ==  NULL){                           //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
  printf("Erro na abertura do arquivo!");           //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
}
Servico serv;                                       //CRIANDO UMA VAREAVEL DE ESTRUTURA DO TIPO SERVIÇO
serv = GetServico();                                //CHAMA FUNCAO PARA LER DADOS DO SERVIÇO // RETORNAR DADOS PARA "SERV".
printf("INFORME ID DO CARRO DESEJADO: ");
scanf("%d",&serv.idCar);                            //LER ID DO CARRO QUE RECEBERAR O SERVIÇO
system("cls");

printf("|-------------------------------|\n");
printf("|     ESCOLHA FUNCIONARIO       |\n");
printf("|-------------------------------|\n");
Funcionario fun;                                    //CRIANDO UMA VAREAVEL DE ESTRUTURA DO TIPO FUNCIONARIO.
FILE *arq_funcionario;                              //PONTEIRO PARA ARQUIVO
arq_funcionario = fopen("arquivo_funcionario.txt", "r"); //ABRIR ARQUIVO FUNCIONARIO. | "R" ABRE ARQUIVO PARA LEITURA
while(fscanf(arq_funcionario,"%s %s %s %d",fun.nome,fun.cpf,fun.endereco,&fun.idFun)!= EOF){ //LISTAR OS FUNCIONARIOS PARA ESCOLHER UM RESPONSAVEL PELO SERVIÇO.
  printf("NOME: %s\nCPF: %s\nENDERECO: %s\nID FUNCIONARIO: %d\n=================================\n",fun.nome,fun.cpf,fun.endereco,fun.idFun);
}
fclose(arq_funcionario);                            //FECHAR ARQUIVO FUNCIONARIO
printf("INFORME ID DO FUNCIONARIO PARA O SERVICO: "); 
scanf("%d",&serv.idFun);                            //LER ID DO FUNCIONARIO SELECIONADO
system("pause");
system("cls");

fprintf(arq_servico,"%s %s %d %d %d\n",serv.titulo,serv.preco,serv.idServ,serv.idFun,serv.idCar); //GRAVAR DADOS DA VAREAVEL "SERV" NO ARQUIVO SERVIÇO
fclose(arq_servico);                                //FECHAR ARQUIVO SERVIÇO
printf("Servico Cadastrado com Sucesso\n\n");       //MENSAGEM DE CONCLUSSAO
system("pause");
system("cls");
```

# CONSULTAR
Consultar cliente
============
```bash
```
Consultar funcionario
===========
```bash
```
Consultar serviço
===========
```bash
```

# LISTAR
Listar cliente
===========
```bash
```
Listar funcionario
===========
```bash
```
Listar serviço
===========
```bash
```

# EXCLUIR
Excluir cliente
===========
```bash
```
Excluir funcionario
===========
```bash
```
Excluir serviço
==========
```bash
```
