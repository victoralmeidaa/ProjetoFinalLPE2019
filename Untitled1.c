#include <stdio.h>
#include <string.h>
#include <ctype.h>

main(){
	char cpf[11];
	int len;
	int i,cond;
	do{
        cond=0;
		printf("\nDigite o cpf com 11 digitos:\n");
		setbuf(stdin,NULL);
		scanf("%s",&cpf);
		len = strlen(cpf);
		if (len == 11){
            for(i=0; i<len; i++){
                if(!isdigit(cpf[i])){
                    cond = 1;
                }
            }
		}else{
            printf("\nQUANTIDADE DE NUMEROS INVALIDA!\n");
		}
        if(cond == 1){
            printf("\nVALOR INVALIDO\n");
        }
	}while(len != 11  || cond != 0);
}
