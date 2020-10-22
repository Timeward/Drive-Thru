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
    char Nomeprod[20+1]; /* +1 espa�o para comportar o null terminator \0 */
    float Custoprod;
}produto; /* Defini��o de estrutura, ou seja, o nome da estrutura */

/* Variaveis globais */
produto reg[20];
int i, j, k;

/* Fun��es */
void cadastra_prod(void){
    produto * pont;
    char decisao;
	i = 0;
	do{
	    system("cls");
	    reg[i].Codprod = i+1;
	    printf("\n  CADASTRO DE PRODUTOS -->\n");
	    printf("\n  C�digo autonum�rico do produto: %i", reg[i].Codprod);
	    printf("\n  Digite o nome do produto:  ");
	    gets(reg[i].Nomeprod);
	    printf("  Digite o custo do produto:  ");
	    scanf("%f", &reg[i].Custoprod);
	    fflush(stdin);
	    system("cls");
	    printf("\n  Cadastro realizado.  Deseja cadastrar outro produto?");
        printf("\n  Digite qualquer tecla para para sim ou [n/N] para n�o.");	//limpar buffer do teclado apos cada loop
	    decisao = getche();
	    i++;
	}
	while((decisao != 'n') && (decisao != 'N'));
}


void gera_lista_prod(void){
	//Vari�veis locais da fun��o gera_lista_prod
    FILE * arq; /* arq � uma vari�vel que referencia o arquivo que conter� a lista */
    /* Abrir o arquivo */
    arq = fopen("C:\\Users\\chase\\OneDrive\\�rea de Trabalho\\LG1A1\\LISTAPRODUTOS.txt","a");//Lembrar de mudar o endere�o para o desejado na m�quina
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
        printf("\n  C�digo do produto --> %d", reg[j].Codprod);
        printf("\n  Nome do produto   --> %s", reg[j].Nomeprod);
        printf("\n  Custo do produto  --> %f", reg[j].Custoprod);
    }
    printf("\n\n  Fim da aplica��o. Os novos cadastros foram adicionados � lista de produtos.\n\n");
    system("pause");
    return(0);
}
