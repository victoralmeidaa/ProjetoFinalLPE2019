# Projeto Final - Linguagem de Programação Estruturada 2019.2
## Sistema de Genstão Lavajato
### Funções 

<!--ts-->
   * [Criar](#Criar)
      - [x] [Cadastro cliente](#Cadastro-cliente)
      - ↳ Cadastrar carro
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
Cadastro cliente
===========

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
