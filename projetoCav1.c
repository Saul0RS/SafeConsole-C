#include <stdio.h>
#include <string.h>

// ---------- Helpers ----------

void limpar_buffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void string_para_hex(char *src, char *dest, int tam){
    dest[0] = '\0';
    char temp[8];
    for (int i = 0; src[i] != '\0'; i++){
        snprintf(temp, sizeof(temp), "%02X ", (unsigned char)src[i]);
        if ((int)strlen(dest) + (int)strlen(temp) >= tam - 1){
            break;
        }
        strcat(dest, temp);
    }
}

// ---------- Etapa 1 ----------

char* mascara_dados(char dado[50]){
    static char copia[50];
    strcpy(copia, dado);
    int len = strlen(copia);
    if (len <= 4) {
        return copia;
    }
    for (int i = 0; i < len - 4; i++){
        copia[i] = '*';
    }
    return copia;
}

char* validar_senha(char senha[50]){
    int contM = 0, contm = 0, contnum = 0;

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
                        }
                        return "Sua senha n tem numeros\n";
                    }
                }
                return "Sua senha n tem letra minuscula\n";
            }
        }
        return "Sua senha n tem letra maiuscula\n";
    }
    else{
        return "Sua senha é curta demais !!!\n";
    }
}

// ---------- Etapa 2 ----------

char* cifrar_cesar(char palavrac[50], int chavec){
    static char copia[50];
    strcpy(copia, palavrac);
    for (int i = 0; copia[i] != '\0'; i++){
        if (copia[i] >= 97 && copia[i] <= 122){
            copia[i] = 97 + (copia[i] - 97 + chavec) % 26;
        }
        else if (copia[i] >= 65 && copia[i] <= 90){
            copia[i] = 65 + (copia[i] - 65 + chavec) % 26;
        }
    }   

    return copia;
}

char* decifrar_cesar(char palavrac[50], int chavec){
    static char copia[50];
    strcpy(copia, palavrac);
    for (int i = 0; copia[i] != '\0'; i++){
        if (copia[i] >= 97 && copia[i] <= 122){
            copia[i] = 97 + (copia[i] - 97 - chavec % 26 + 26) % 26;
        }
        else if (copia[i] >= 65 && copia[i] <= 90){
            copia[i] = 65 + (copia[i] - 65 - chavec % 26 + 26) % 26;
        }
    }
    return copia;
}

char* cifrar_xor(char palavrax[50], char chavex){
    static char copia[50];
    strcpy(copia, palavrax);
    for (int i = 0; copia[i] != '\0'; i++){
        copia[i] = copia[i] ^ chavex;
    }
    return copia;
}

void cifrar_log_cesar(char historico[][256], int totalLogs, int chavec, char logCifrado[][256]){
    for (int i = 0; i < totalLogs; i++){
        strcpy(logCifrado[i], historico[i]);
        for (int j = 0; logCifrado[i][j] != '\0'; j++){
            if (logCifrado[i][j] >= 97 && logCifrado[i][j] <= 122){
                logCifrado[i][j] = 97 + (logCifrado[i][j] - 97 + chavec) % 26;
            }
            else if (logCifrado[i][j] >= 65 && logCifrado[i][j] <= 90){
                logCifrado[i][j] = 65 + (logCifrado[i][j] - 65 + chavec) % 26;
            }
        }
    }
}

void cifrar_log_xor(char historico[][256], int totalLogs, char chavex, char logCifrado[][256]){
    for (int i = 0; i < totalLogs; i++){
        strcpy(logCifrado[i], historico[i]);
        for (int j = 0; logCifrado[i][j] != '\0'; j++){
            logCifrado[i][j] = logCifrado[i][j] ^ chavex;
        }
    }
}

void registra_log_int(int log, char historico[][256], int *totalLogs){
    if (*totalLogs < 100){
        snprintf(historico[*totalLogs], 256, "Opcao: %d", log);
        (*totalLogs)++;
    } else {
        printf("QUANTIDADE MAXIMA DE LOGS ALCANCADA\n");
    }
}

void registra_log_char(char *log, char historico[][256], int *totalLogs){
    if (*totalLogs < 100){
        snprintf(historico[*totalLogs], 256, "%s", log);
        (*totalLogs)++;
    } else {
        printf("QUANTIDADE MAXIMA DE LOGS ALCANCADA\n");
    }
}

int verifica_log(char *log, char historico[][256], int *totalLogs){
    for (int i = 0; i < *totalLogs; i++){
        if (strcmp(historico[i], log) == 0){
            return i;
        }
    }
    return -1;
}

void lista_log(char historico[][256], int *totalLogs, int tipoCifra, int chave){
    char logCifrado[100][256];

    if (tipoCifra == 1){
        cifrar_log_cesar(historico, *totalLogs, chave, logCifrado);

    } else if (tipoCifra == 2){
        cifrar_log_xor(historico, *totalLogs, (char)chave, logCifrado);

    } else {
        for (int i = 0; i < *totalLogs; i++){
            strcpy(logCifrado[i], historico[i]);
        }
    }

    printf("-===- REGISTRO DE LOGS -===-\n");
    if (tipoCifra == 1){
        printf("Cifra utilizada: Cifra de Cesar\n");
    } else if (tipoCifra == 2){
        printf("Cifra utilizada: XOR\n");
    } else {
        printf("Cifra utilizada: Nenhuma\n");
    }

    for (int i = 0; i < *totalLogs; i++){
        printf("%d - %s\n", i + 1, logCifrado[i]);
    }
}



int main(){
    char historico[100][256];
    char verifica[256];
    int  totalLogs = 0, op1 = -1;

    do {
        printf("\n-===- BEM VINDO AO SAFECONSOLE -===-\n");
        printf("1 - Sanitizar algum dado\n");
        printf("2 - Validador de Senha\n");
        printf("3 - Cifra de Cesar\n");
        printf("4 - Cifrar com XOR\n");
        printf("5 - Logs de Auditoria\n");
        printf("0 - Sair\n");
        printf("R - ");

        scanf("%d", &op1);
        limpar_buffer();
        registra_log_int(op1, historico, &totalLogs);

        switch (op1){

            case 1: {
                char dado[50];
                printf("Digite o dado q voce quer sanitizar: ");
                fgets(dado, sizeof(dado), stdin);
                dado[strcspn(dado, "\n")] = '\0';
                registra_log_char(dado, historico, &totalLogs);

                char *mascarado = mascara_dados(dado);
                printf("Seu dado sanitizado: %s\n", mascarado);
                registra_log_char(mascarado, historico, &totalLogs);
                break;
            }

            case 2: {
                char senha[50];
                printf("Digite a senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0';
                registra_log_char(senha, historico, &totalLogs);

                char *resultado = validar_senha(senha);
                printf("%s", resultado);
                registra_log_char(resultado, historico, &totalLogs);
                break;
            }

            case 3: {
                char palavrac[50], *resultado;
                int  chavec, op2;

                printf("1 - criptografar\n2 - descriptografar\nR - ");
                scanf("%d", &op2);
                limpar_buffer();
                registra_log_int(op2, historico, &totalLogs);

                printf("Digite a palavra: ");
                fgets(palavrac, sizeof(palavrac), stdin);
                palavrac[strcspn(palavrac, "\n")] = '\0';
                registra_log_char(palavrac, historico, &totalLogs);

                printf("Digite a chave: ");
                scanf("%d", &chavec);    
                limpar_buffer();
                registra_log_int(chavec, historico, &totalLogs);

                if (op2 == 1){
                    resultado = cifrar_cesar(palavrac, chavec);
                    printf("A palavra cifrada e: %s\n", resultado);
                    snprintf(historico[totalLogs], 256,"A palavra cifrada e: %s", resultado);
                    totalLogs++;
                    //strcpy(opNome, "cifrada");
                } else if (op2 == 2){
                    resultado = decifrar_cesar(palavrac, chavec);
                    printf("A palavra decifrada e: %s\n", resultado);
                    snprintf(historico[totalLogs], 256,"A palavra decifrada e: %s", resultado);
                    totalLogs++;
                    //strcpy(opNome, "decifrada");
                }

                break;
            }

            case 4: {
                char palavrax[50];
                int  chavex_int;

                printf("Digite a palavra para cifrar ou decifrar: ");
                fgets(palavrax, sizeof(palavrax), stdin);
                palavrax[strcspn(palavrax, "\n")] = '\0';
                registra_log_char(palavrax, historico, &totalLogs);

                printf("Digite a chave usada na cifragem ou decifragem(0-255): ");
                scanf("%d", &chavex_int);
                limpar_buffer();
                registra_log_int(chavex_int, historico, &totalLogs);

                char chavex = (char)chavex_int;
                char *cifrado = cifrar_xor(palavrax, chavex);

                char hexbuf[256];
                string_para_hex(cifrado, hexbuf, 256);

                printf("Hex: %s\nTexto: %s\n", hexbuf, cifrado);

                snprintf(historico[totalLogs], 256, "Texto na forma de hexadecimal: %s | Texto normal: %s", hexbuf, cifrado);
                totalLogs++;
                break;
            }

            case 5: {
                int op3, tipoCifra, chave;

                printf("1 - consultar log\n2 - listar logs\nR - ");
                scanf("%d", &op3);
                limpar_buffer();

                if (op3 == 1){
                    printf("Digite o termo para verificar: ");
                    fgets(verifica, sizeof(verifica), stdin);
                    verifica[strcspn(verifica, "\n")] = '\0';

                    int teste = verifica_log(verifica, historico, &totalLogs);
                    if (teste != -1){
                        printf("Log encontrado na posicao %d: %s\n",
                        teste + 1, historico[teste]);
                    } else {
                        printf("Log nao encontrado!\n");
                    }
                } else if (op3 == 2){
                    printf("Escolha a cifra para os logs:\n1 - Cifra de Cesar\n2 - XOR\nR - ");
                    scanf("%d", &tipoCifra);
                    limpar_buffer();

                    printf("Digite a chave da cifra: ");
                    scanf("%d", &chave);
                    limpar_buffer();

                    lista_log(historico, &totalLogs, tipoCifra, chave);
                }
                break;
            }

            case 0:
                printf("TCHAU\n");
                break;

            default:
                printf("Opcao invalida !!!\n");
                break;
        }

    } while (op1 != 0);

    return 0;
}