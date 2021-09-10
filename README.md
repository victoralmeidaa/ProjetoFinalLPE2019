# Projeto Final - Linguagem de Programação Estruturada 2019.2
## Sistema de Genstão Lavajato
### Funções 

<!--ts-->
   * [Criar](#Criar)
      - [x] [Cliente](#Cliente)
      - Estrutura de dados do cliente.
      - Função para ler dados do cliente.
      - Gravar dados do cliente no arquivo txt.
      ↳
      
      - [x] [Carro](#Carro)
      - Estrutura de dados de carro
      - Cadastrar carro
      : Logo após cadastrar o cliente o sistema pede para que seja cadastrado o veículo associado a este cliente.
  
      - [x] [Cadastro de Funcionario](#funcionario)
      - ↳ 
      : Cadastra funcionario no sistema
      
      - [x] [Cadastro de Serviço](#serviço)
      - ↳ Escolher Funcionario
      : Escolher um funcionario que ficará responsável pela serviço.
      
   * [Consultar](#Consultar)
      - [x] [Consulta de Cliente](#consultar-cliente)
      - ↳ 
      : Consulta cliente cadastrado no sistema, exibe dados do cliente e veiculo(s).
      
      - [x] [Consulta de Funcionario](#consultar-funcionario)
      - ↳ 
      : Consulta funcionarios cadastrados no sistema.
      
      - [x] [Consulta de Serviço](#consultar-serviço)
      - ↳ 
      : Consulta serviço cadastrado no sistema, exibe dados do serviço, funcionario responsável, cliente e veículo(s) designado(s). 
       
   * [Listar](#Listar)
      - [x] [Listar Cliente(s)](#listar-cliente)
      - ↳ 
      : Lista todos os clientes cadastrados no sistema.
      
      - [x] [Listar Funcionario(s)](#listar-funcionario)
      - ↳ 
      : Lista todos os funcionarios cadastrados no sistema.
      
      - [x] [Listar Serviço(s)](#listar-serviço)
      - ↳ 
      : Lista todos os serviços cadastrados no sistema.
      
   * [Excluir](#Excluir)
      - [x] [Excluir Cliente](#excluir-cliente)
      - ↳ 
      : Excluir cliente selecionado.
      
      - [x] [Excluir Funcionario](#excluir-funcionario)
      - ↳ 
      : Excluir funcionario selecionado.
      
      - [x] [Excluir Serviço](#excluir-serviço)
      - ↳ 
      : Excluir serviço selecionado.
<!--te-->
##


# Criar
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
     
  do{                                                 //INICIO "DO WHILE"
  cond=0;
  printf("DIGITE CPF COM 11 DIGITOS: ");            
  setbuf(stdin,NULL);
  gets(&cli.cpf);				    //LER CPF CLIENTE
	len = strlen(cli.cpf);			    //GUARDA A QUANTIDADE DE CARACTERES INFORMADOS EM "CLI.CPF"
	if (len == 11){				    
     	   for(i=0; i<len; i++){                    //LAÇO PARA LER TODOS OS 11 CARACTERES DE "CLI.CPF"
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
  }while(len != 11  || cond != 0);                     //FIM "DO WHILE"


     printf("ENDERECO: ");				    
     setbuf(stdin,NULL);    				    
     gets(&cli.endereco); 			     //LER ENDERECO DO CLIENTE
     printf("ID: ");				    
     scanf("%d",&cli.idCli);		             //LER ID DO CLIENTE
     return cli;                                     //FUNCAO RETORNA ESTRUTURA DO TIPO CLIENTE.
}
```



- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO.TXT
```bash
FILE *arq_cliente;                                //PONTEIRO PARA ARQUIVO
arq_cliente = fopen("arquivo_cliente.txt", "a");  //ABRIR ARQUIVO CLIENTE | "A" ABRE O ARQUIVO PARA GRAVAÇÃO.
if(arq_cliente ==  NULL){                         //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CLIENTE
    printf("Erro na abertura do arquivo!");       //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
}
Cliente cli;                                      //CRIANDO UMA VAREAVEL "CLI" DO TIPO DA STRUCT, CLIENTE.
cli = GetCliente();                               //CHAMA FUNCAO PARA LER DADOS DO CLIENTE // RETORNAR DADOS PARA "CLI".

fprintf(arq_cliente,"%s %s %s %d\n",cli.nome,cli.cpf,cli.endereco,cli.idCli); //GRAVAR DADOS DA VAREAVEL "CLI" CLIENTE NO ARQUIVO CLIENTE
fclose(arq_cliente);                              //FECHAR ARQUIVO CLIENTE
printf("Cliente Cadastrado com Sucesso\n\n");     //MENSAGEM DE CONCLUSSAO
int auxCli;                                       //CRIANDO VAREAVEL AUXILIAR PARA GUARDAR ID DO CLIENTE.
auxCli = cli.idCli;                               //GUARDANDO ID DO CLIENTE NA VAREAVEL AUXILIAR.
system("pause");
system("cls");
```


Cadastrar carro
===========
- ESTRUTURA CARRO
```bash
typedef struct Carro{ //ESTRUTURA DO TIPO CARRO
    char modelo[20];
    char cor[20];
    char placa[10];
    int idCar;
    int idCli;
}
Carro;
```

- FUNÇÃO LER DADOS CARRO
```bash
Carro GetCarro(){ 				   //FUNCAO DO TIPO CARRO PARA LER DADOS DE CARROS.
    Carro car;					   //CRIANDO VAREAVEL DE ESTRUTURA DO TIPO CARRO.
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
    return car;                                    //FUNCAO RETORNA ESTRUTURA DO TIPO CARRO.
}
```

- APLICANDO A FUNÇÃO | GUARDANDO DADOS NO ARQUIVO.TXT
```bash
FILE *arq_carro;
arq_carro = fopen("arquivo_carro.txt", "a");      //ABRIR ARQUIVO CARRO. "A" ABRE O ARQUIVO PARA GRAVAÇÃO.
if(arq_carro ==  NULL){                           //VERIFICAR SE OUVE ERRO AO ABRIR O ARQUIVO CARRO
    printf("ERRO NA ABERTURA DO ARQUIVO!");       //RETORNAR MENSAGEM DE ERRO CASO OUVER ERRO QUANDO ABRIR O ARQUIVO
    return 1;
}
Cliente cli;                                      
Carro car;                                        //CRIANDO UMA VAREAVEL "CAR" DO TIPO STRUCT, CARRO.
car = GetCarro();                                 //CHAMA FUNCAO PARA LER DADOS DO CARRO // RETORNAR DADOS PARA "CAR"
car.idCli = auxCli;                               //COPIANDO VAREAVEL AUXILIAR COM O ID DO CLIENTE PARA ID DO CARRO
fprintf(arq_carro,"%s %s %s %d %d\n",car.modelo,car.cor,car.placa,car.idCar,car.idCli); //GRAVAR DADOS DO "CAR" CARRO NO ARQUIVO CARRO
fclose(arq_carro);                                //FECHAR ARQUIVO CARRO
printf("Carro Cadastrado com Sucesso\n");         //MENSAGEM DE CONCLUSSAO
system("pause");
system("cls");;
```
