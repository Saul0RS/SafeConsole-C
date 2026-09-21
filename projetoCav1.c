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

void registra_log(char *log, char historico[][256], int *totalLogs){
    if (*totalLogs < 100){
        strncpy(historico[*totalLogs], log, 255);
        historico[*totalLogs][255] = '\0';
        (*totalLogs)++;
    }
    else{
        printf("QUANTIDADE MAXIMA DE LOGS ALCANÇADA");
    }  
}

int verifica_log(char *log, char historico[][256], int *totalLogs){
    for (int i = 0; i <*totalLogs; i++){
        if (strcmp(historico[i], log) == 0){
            return i;
        }
    }
    return -1;
}

void lista_log(char historico[][256], int *totalLogs){
    printf("-===- REGISTRO DE LOGS DIGITADOS DO USUARIO -===-\n");
    for (int i = 0; i != *totalLogs; i++){
        printf("%d - %s", i, historico[i]);
    }
}

int main(){
    char historico[100][256], verifica[256];
    int  totalLogs = 0, op1 = -1;

    while (op1 != 0){
    printf("\n-===- BEM VINDO AO SAFECONSOLE -===-\n");
    printf("Selecione as opcoes do menu:\n");
    printf("1 - Sanitizar algum dado\n");
    printf("2 - Validador de Senha\n");
    printf("3 - Cifra de Cesar\n");
    printf("4 - Cifrar com XOR\n");
    printf("5 - Logs de Auditoria\n");
    printf("0 - Sair\n");
    printf("R - ");
    scanf("%d",&op1);

    switch (op1){
        case 1:
            char dado[50];
            printf("Digite o dado q voce quer sanitizar: ");
            getchar();
            fgets(dado,sizeof(dado),stdin);
            registra_log(dado, historico, &totalLogs);
            printf("Seu dado sanitizado: %s", mascara_dados(dado));
            break;
        
        case 2: 
            char senha[50];
            printf("Digite a senha para ser validada: ");
            getchar();
            fgets(senha,sizeof(senha),stdin);
            registra_log(senha, historico, &totalLogs);
            printf(validar_senha(senha));
            break;

        case 3: 
            char palavrac[50];
            int chavec, op2;    
            
            printf("Digite a opcao:\n1 - criptografar\n2 - descriptografar\n");
            scanf("%d",&op2);
            if (op2 == 1){
                printf("Digite uma palavra a ser cifrada: ");
                getchar();
                fgets(palavrac,sizeof(palavrac),stdin);
                registra_log(palavrac, historico, &totalLogs);
                printf("Digite o valor da chave da cifragem: ");
                scanf("%d", &chavec);
                //registra_log(chavec, historico, &totalLogs);
                printf("A palavra na forma cifrada e: %s", cifrar_cesar(palavrac,chavec));
            }

            else if (op2 == 2){
                printf("Digite uma palavra a ser decifrada: ");
                getchar();
                fgets(palavrac,sizeof(palavrac),stdin);
                registra_log(palavrac, historico, &totalLogs);
                printf("Digite a chave usada na cifragem para decifrar: ");
                scanf("%d",&chavec);
                //registra_log(chavec, historico, &totalLogs);
                printf("A palavra decifrada e: %s", decifrar_cesar(palavrac, chavec));
            }
            break;
        
        case 4:
            char palavrax[50];
            int chavex;

            printf("Digite a palavra para cifrar OU decifrar: ");
            getchar();
            fgets(palavrax,sizeof(palavrax),stdin);
            registra_log(palavrax, historico, &totalLogs);
            printf("Digite a chave usada para cifrar ou decifrar: ");
            scanf("%d",&chavex);
            //registra_log(chavex, historico, &totalLogs);
            printf("A palavra cifrada em hexadecimal e: %02x\n e em texto normal: %s", cifrar_xor(palavrax, chavex));
            break;

        case 5:
            int op3;    
            
            printf("Digite a opcao:\n1 - consultar log\n2 - listar logs\n");
            scanf("%d",&op3);
            if (op3 == 1){
                printf("Digite a algo para verificar se ja foi digitado ou nao: ");
                getchar();
                fgets(verifica,sizeof(verifica),stdin);
                int teste = verifica_log(verifica, historico, &totalLogs);
                if (teste != -1){
                    printf("log encontrado na posicao %d do historico de logs: %s", teste, verifica);
                }
                else{
                    printf("Log nao encontrato !!!");
                }
                break;
            }
            else if (op3 == 2){
                lista_log(historico, &totalLogs);
            }

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