#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* mascara_dados(char dado[50]){
    for (int i = 0; i != strlen(dado) - 5; i++){
        dado[i] = '*';
    }
    return dado;
}

char* validar_senha(char senha[50]){
    int contM = 0, contm = 0, contnum;

    if (strlen(senha) >= 8){
        for (int i = 0; i != strlen(senha); i++){
            if (senha[i] >= 65 && senha[i] <= 90){
                contM = 1;
            }
            if (contM){
                for (int i = 0; i != strlen(senha); i++){
                    if (senha[i] >= 97 && senha[i] <= 122){
                    contm = 1;
                    }                
                    if (contm){
                        for (int i = 0; i != strlen(senha); i++){
                            if (senha[i] >= 48 && senha[i] <= 57){
                                contnum = 1;
                            }
                            if(contnum){
                                return "parabens senha forte\n";
                            }
                        }return "Sua senha n tem numeros\n";
                    }
                }return "Sua senha n tem letra minuscula\n";
            }
        }return "Sua senha n tem letra maiuscula\n";
    }
    else{
        return "Sua senha é curta demais !!!\n";
    }
    
}

int main(){
    int op = -1;
    while (op != 0){
    printf("-===- BEM VINDO AO SAFECONSOLE -===-\n");
    printf("Selecione as opcoes do menu:\n");
    printf("1 - Sanitizar algum dado\n");
    printf("2 - Validador de Senha\n");
    printf("0 - Sair\n");
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
        
        case 2: 
            char senha[50];
            printf("Digite a senha para ser validada: ");
            getchar();
            fgets(senha,sizeof(senha),stdin);
            //printf("%s", validar_senha(senha));
            printf(validar_senha(senha));
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