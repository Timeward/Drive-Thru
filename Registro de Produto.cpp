/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* Constantes pre definidas */

/* Tipos de dados pre definidos */
typedef struct{
    /* Campos da estrutura */
    int Codprod;
    char Nomeprod[20+1]; /* +1 espaço para comportar o null terminator \0 */
    float Custoprod;
}produto; /* Definição de estrutura, ou seja, o nome da estrutura */

/* Variaveis globais */
produto reg[50];
int i, j, k;

/* Funções */
void cadastra_prod(void){
	system("cls");
	i = 0;
	//while(1){
	    printf("\n  Codigo do produto: %i", i+1); /* Modo tosco de inicializar, ilusório.*/
	    printf("\n  Digite o nome do produto:  ");
	    gets(reg[i].Nomeprod);
	    printf("\n  Digite o custo do produto:  ");
	    scanf("%f", &reg[i].Custoprod);
	    fflush(stdin);	//limpar buffer do teclado
	    reg[i].Codprod = i+1;
	    //i++;
	//}
}

void consulta_prod(void){
    system("cls");
    printf("\n===================================================================");
    printf("\n                      CADASTRO DE PRODUTOS                         ");
    printf("\n===================================================================");
    printf("\n   CODIGO                    NOME                         CUSTO    ");
    printf("\n===================================================================");
	for(j=0;j<=i;j++){ 
		printf("\n   %i                         %s                         %.2f   ",
	           reg[j].Codprod, reg[j].Nomeprod, reg[j].Custoprod);
    	printf("\n===================================================================\n");
    }
    system("pause");
}

void gera_lista_prod(void){
	//Variáveis locais da função gera_lista_prod
    FILE * arq; /* arq é uma variável que referencia o arquivo que conterá a lista */
    /* Abrir o arquivo */
    arq = fopen("C:\\saidadecodigos\\produtos.txt","a"); /* w se refere ao modo de abertura do arquivo, w cria um arquivo do zero e substitui um arquivo com nome já existente. */    
    /* Gravar os dados dos produtos */
    for(k=0;k<=i;k++){
		fwrite(&reg[k], 1 , sizeof(produto) , arq);
    }
    fclose(arq);//Fechar o arquivo
}

/* Corpo do programa */
int main (){
    cadastra_prod();
    consulta_prod();
    gera_lista_prod();
    system("pause");
    return(0);
}
