/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

/* Constantes pre definidas */

/* Tipos de dados pre definidos */
typedef struct{
    /* Campos da estrutura */
    int Codprod;
    char Nomeprod[20+1]; /* +1 espaço para comportar o null terminator \0 */
    float Custoprod;
}produto; /* Definição de estrutura, ou seja, o nome da estrutura */

/* Variaveis globais */
produto reg[20];
int i, j, k;

/* Funções */
void cadastra_prod(void){
    produto * pont;
    char decisao;
	i = 0;
	do{
	    system("cls");
	    reg[i].Codprod = i+1;
	    printf("\n  CADASTRO DE PRODUTOS -->\n");
	    printf("\n  Código autonumérico do produto: %i", reg[i].Codprod);
	    printf("\n  Digite o nome do produto:  ");
	    gets(reg[i].Nomeprod);
	    printf("  Digite o custo do produto:  ");
	    scanf("%f", &reg[i].Custoprod);
	    fflush(stdin);
	    system("cls");
	    printf("\n  Cadastro realizado.  Deseja cadastrar outro produto?");
        printf("\n  Digite qualquer tecla para para sim ou [n/N] para não.");	//limpar buffer do teclado apos cada loop
	    decisao = getche();
	    i++;
	}
	while((decisao != 'n') && (decisao != 'N'));
}


void gera_lista_prod(void){
	//Variáveis locais da função gera_lista_prod
    FILE * arq; /* arq é uma variável que referencia o arquivo que conterá a lista */
    /* Abrir o arquivo */
    arq = fopen("C:\\Users\\chase\\OneDrive\\Área de Trabalho\\LG1A1\\LISTAPRODUTOS.txt","a");//Lembrar de mudar o endereço para o desejado na máquina
    /* Gravar os dados dos produtos */
    for(k=0;k<=i;k++){
		fwrite(&reg[k], 1 , sizeof(produto) , arq);
    }
    fclose(arq);//Fechar o arquivo
}

/* Corpo do programa */
int main (){
    setlocale(LC_ALL,"portuguese");
    cadastra_prod();
    gera_lista_prod();
    for(j=0;j<i;j++){
        printf("\n");
        printf("\n  Código do produto --> %d", reg[j].Codprod);
        printf("\n  Nome do produto   --> %s", reg[j].Nomeprod);
        printf("\n  Custo do produto  --> %f", reg[j].Custoprod);
    }
    printf("\n\n  Fim da aplicação. Os novos cadastros foram adicionados à lista de produtos.\n\n");
    system("pause");
    return(0);
}
