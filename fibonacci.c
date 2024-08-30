#include <stdio.h>

int main() {
    int num, a = 0, b = 1, fib = 0;

    // Solicita ao usuário um número
    printf("Informe um número: ");
    scanf("%d", &num);

    // Verifica se o número é 0 ou 1, que são os primeiros números da sequência
    if (num == 0 || num == 1) {
        printf("O número %d pertence à sequência de Fibonacci.\n", num);
        return 0;
    }

    // Calcula a sequência de Fibonacci até encontrar o número ou até o valor ser maior que o número informado
    while (fib < num) {
        fib = a + b;
        a = b;
        b = fib;
    }

    // Verifica se o número informado é igual ao último número da sequência calculada
    if (fib == num) {
        printf("O número %d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}