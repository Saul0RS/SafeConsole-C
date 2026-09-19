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

char* cifrar_cesar(char palavrac[50], int chavec){
    for (int i = 0; palavrac[i] != '\0'; i++){
        palavrac[i] = palavrac[i] + chavec;
    }
    return palavrac;
}

char* decifrar_cesar(char palavrac[50], int chavec){
    for (int i = 0; palavrac[i] != '\0'; i++){
        palavrac[i] = palavrac[i] - chavec;
    }
    return palavrac;
}

char* cifrar_xor(char palavrax[24], int chavex) {
    for (int i = 0; palavrax[i] != '\0'; i++) {
        palavrax[i] = palavrax[i] ^ chavex;   
    }
    return palavrax;
}

int main(){
    int op1 = -1;
    while (op1 != 0){
    printf("\n-===- BEM VINDO AO SAFECONSOLE -===-\n");
    printf("Selecione as opcoes do menu:\n");
    printf("1 - Sanitizar algum dado\n");
    printf("2 - Validador de Senha\n");
    printf("3 - Cifra de Cesar\n");
    printf("4 - Cifrar com XOR\n");
    printf("0 - Sair\n");
    printf("R - ");
    scanf("%d",&op1);

    switch (op1){
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

        case 3: 
            char palavrac[50];
            int chavec, op2;
            
            printf("Digite a opcao:\n1 - criptografar\n2 - descriptografar\n");
            scanf("%d",&op2);
            if (op2 == 1){
                printf("Digite uma palavra a ser cifrada: ");
                scanf("%s", palavrac);
                printf("Digite o valor da chave da cifragem: ");
                scanf("%d", &chavec);
                printf("A palavra na forma cifrada e: %s", cifrar_cesar(palavrac,chavec));
            }

            else if (op2 == 2){
                printf("Digite uma palavra a ser decifrada: ");
                scanf("%s",palavrac);
                printf("Digite a chave usada na cifragem para decifrar: ");
                scanf("%d",&chavec);
                printf("A palavra decifrada e: %s", decifrar_cesar(palavrac, chavec));
            }
            break;
        
        case 4:
            char palavrax[50];
            int chavex;

            printf("Digite a palavra para cifrar OU decifrar: ");
            scanf("%s",palavrax);
            printf("Digite a chave usada para cifrar ou decifrar: ");
            scanf("%d",&chavex);
            printf("A palavra cifrada em hexadecimal e: %02x\n e em texto normal: %s", cifrar_xor(palavrax, chavex));
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