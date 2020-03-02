#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"

#define BUFFER 64
int main(void)
{
    while(1){
        server();
    }
}

void server(){
    // Credentials
    int id = 0;
    char username[BUFFER];
    char password[BUFFER];

    printf("%s", "mention your identity please\n");
    gets(username);
    printf("%s", "password:\n");
    gets(password);

    id = check_credentials(username, password);

    switch (id)
    {
        case 1:
            printf("%s", "Hi la Ruche!\n");
            break;
        case 2:
            printf("%s", "Hi admin!\n");
            break;
        default:
            printf("%s", "Bad authentication\n");
            break;
    }
}

int check_credentials(char* username, char* password) {
    if (strcmp(username,"la_ruche") == 0) {
        char* ciphered = cipher_passwd(password);
        if (strcmp(cipher_passwd(password), "#8'06;") == 0) {
            free(ciphered);
            return 1;
        }
        else {
            free(ciphered);
            return -1;
        }
    }
    else if (strcmp(username, "admin") == 0){
        char* ciphered = cipher_passwd(password);
        if (strcmp(ciphered, "&-(-spqc") == 0) {
            free(ciphered);
            return 2;
        }
        else {
            free(ciphered);
            return -1;
        }
    }
    else {
        return -1;
    }
}

char* cipher_passwd(char* passwd)
{
    char* output = malloc(strlen(passwd)*sizeof(char));
    for (int i = 0; i < strlen(passwd); i++) {
        output[i] = passwd[i] ^ 0x42;
    }
    return output;
}
