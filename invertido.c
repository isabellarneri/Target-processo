#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Função para inverter a string
void inverter_string(char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;
    char temp;

    // Troca os caracteres do início e do fim até o meio da string
    while (inicio < fim) {
        temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inicio++;
        fim--;
    }
}

int main() {
    char str[MAX_LENGTH];

    // Solicita ao usuário para informar a string
    printf("Informe uma string para inverter (máximo %d caracteres): ", MAX_LENGTH - 1);
    fgets(str, MAX_LENGTH, stdin);

    // Remove o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = '\0';

    // Inverte a string
    inverter_string(str);

    // Exibe a string invertida
    printf("String invertida: %s\n", str);

    return 0;
}