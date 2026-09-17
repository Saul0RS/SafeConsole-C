#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* mascara_dados(char dado[50]){
    for (int i = 0; i != strlen(dado) - 5; i++){
        dado[i] = '*';
    }
    return dado;
}


int main(){
    int op = -1;
    while (op != 0){
    printf("-===- BEM VINDO AO SAFECONSOLE -===-\n");
    printf("Selecione as opcoes do menu:\n");
    printf("1 - Sanitizar algum dado\n");
    printf("R - ");
    scanf("%d",&op);

    switch (op){
        case 1:
            char dado[50];
            printf("Digite o dado q voce quer sanitizar: ");
            getchar();
            fgets(dado,sizeof(dado),stdin);
            printf("Seu dado sanitizado: %s", mascara_dados(dado));
            break;
        
        case 0:
            printf("TCHAU");
            break;
            
        default:
            printf("Opcao invalida !!!");
            break;
        
        }


    }


    return 0;
}