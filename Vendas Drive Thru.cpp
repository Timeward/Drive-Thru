#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

typedef struct{
    int Codprod;
    char Nomeprod[20+1]; /* +1 espaço para comportar o null terminator \0 */
    float Custoprod;
}produto;

FILE * arq;
int i;
produto reg[20];

int main(){
	setlocale(LC_ALL, "Portuguese");
	arq = fopen("C:\\Users\\chase\\OneDrive\\Área de Trabalho\\LG1A1\\LISTAPRODUTOS.txt","r");//Lembrar de mudar o endereço para o desejado na máquina
	if(arq == NULL){
 		printf("Erro ao abrir a lista de produtos\n");
	}
	else{
		printf("Faça seu pedido:");
		do{
			fread(&reg[i], sizeof(produto), 1, arq);
			printf("\n\n%i: %s", reg[i].Codprod, reg[i].Nomeprod);
			printf("       R$%.2f", reg[i].Custoprod);
		}while(reg[i].Codprod != 0);
		printf("\r                     ");//Limpa a última linha do output
    }
}
