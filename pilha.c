#include <stdio.h>
#include <stdlib.h>


void menuOpcao(int *pratos, int tamanho, int *primeiro){

    int opcao;
    int *topo = calloc(1, sizeof(int));
    do{
        printf("\n-------------------");
        printf("\n1 ADICIONAR PRATO");
        printf("\n2 REMOVER PRATO");
        printf("\n3 MOSTRAR TODOS OS PRATOS");
        printf("\n4 FIM DO PROGRAMA");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                adicionarPrato(pratos, tamanho, topo);
                pratos++;
                break;
            case 2:
                int volta = removerPrato(pratos, topo);
                printf("\nPRATO RETORNADO: %d", volta);
                break;
            case 3:
                mostrarPratos(pratos, tamanho, topo, primeiro);
                break;
            case 4:
                printf("\nFIM DO PROGRAMA");
                return;
            default:
                printf("\nOPCAO NAO RECONHECIDA");
                break;
        }
    }
    while(opcao!=4);
}

void adicionarPrato(int *prato, int tamanho, int *topo){  
    if(*topo >= tamanho){
        printf("\nPILHA JA ESTA CHEIA\n");
        return;
    }
    int valor;
    printf("\ntopo = %d", *topo);
    printf("\nDigite o valor a adicionar: ");
    scanf("%d", &valor);
    *prato = valor;
    *topo = *topo+1;
}

int removerPrato(int *prato, int *topo){
    if(*topo <= 0){
        printf("\nPILHA JA ESTA VAZIA\n");
        return 0;
    }

    *topo = *topo - 1;
    prato = prato - 1;
    return *prato;
}

void mostrarPratos(int *prato, int tamanho, int *topo, int *primeiro){
    if(*topo <= 0){
        printf("\n-------------------");

        printf("\nPILHA VAZIA");
        return;
    }
    printf("\ntopo = %d", *topo);
    int i;
    int *copiaPrimeiro = primeiro;
    for(i=0; i<*topo; i++, copiaPrimeiro++)     printf("\nVALOR %d = %d", i+1, *copiaPrimeiro);
}

int main(){

    int tamanho;
    printf("Digite o tamanho da pilha: ");
    scanf("%d", &tamanho);

    int *pratos;
    pratos = calloc(tamanho, sizeof(int));

    if(!pratos){
        printf("ERRO AO ALOCAR");
        exit(1);
    }

    int *primeiro = pratos;
    menuOpcao(pratos, tamanho, primeiro);
    return 0;
}