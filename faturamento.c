#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

// Função para calcular o menor valor de faturamento
double calcular_menor_valor(double faturamento[], int tamanho) {
    double menor = faturamento[0];
    for (int i = 1; i < tamanho; i++) {
        if (faturamento[i] < menor) {
            menor = faturamento[i];
        }
    }
    return menor;
}

// Função para calcular o maior valor de faturamento
double calcular_maior_valor(double faturamento[], int tamanho) {
    double maior = faturamento[0];
    for (int i = 1; i < tamanho; i++) {
        if (faturamento[i] > maior) {
            maior = faturamento[i];
        }
    }
    return maior;
}

// Função para calcular o número de dias com faturamento acima da média
int calcular_dias_acima_da_media(double faturamento[], int tamanho, double media) {
    int contador = 0;
    for (int i = 0; i < tamanho; i++) {
        if (faturamento[i] > media) {
            contador++;
        }
    }
    return contador;
}

int main() {
    FILE *file = fopen("dados_faturamento.json", "r");
    if (file == NULL) {
        perror("Não foi possível abrir o arquivo");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long tamanho_arquivo = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *conteudo = malloc(tamanho_arquivo + 1);
    fread(conteudo, 1, tamanho_arquivo, file);
    fclose(file);
    conteudo[tamanho_arquivo] = '\0';

    cJSON *json = cJSON_Parse(conteudo);
    free(conteudo);

    if (json == NULL) {
        printf("Erro ao parsear JSON\n");
        return EXIT_FAILURE;
    }

    cJSON *faturamento_json = cJSON_GetObjectItemCaseSensitive(json, "faturamento_diario");
    int tamanho = cJSON_GetArraySize(faturamento_json);
    double *faturamento = malloc(tamanho * sizeof(double));

    double soma = 0;
    int contagem = 0;

    for (int i = 0; i < tamanho; i++) {
        cJSON *item = cJSON_GetArrayItem(faturamento_json, i);
        double valor = item->valuedouble;
        if (valor > 0) {
            faturamento[contagem++] = valor;
            soma += valor;
        }
    }

    if (contagem == 0) {
        printf("Não há dados de faturamento para calcular.\n");
        free(faturamento);
        cJSON_Delete(json);
        return EXIT_SUCCESS;
    }

    double media_mensal = soma / contagem;
    double menor_valor = calcular_menor_valor(faturamento, contagem);
    double maior_valor = calcular_maior_valor(faturamento, contagem);
    int dias_acima_da_media = calcular_dias_acima_da_media(faturamento, contagem, media_mensal);

    printf("Menor valor de faturamento: %.2f\n", menor_valor);
    printf("Maior valor de faturamento: %.2f\n", maior_valor);
    printf("Número de dias acima da média: %d\n", dias_acima_da_media);

    free(faturamento);
    cJSON_Delete(json);

    return EXIT_SUCCESS;
}

    // Verifica se o número informado é igual ao último número da sequência calculada
    if (fib == num) {
        printf("O número %d pertence à sequência de Fibonacci.\n", num);
    } else {
        printf("O número %d não pertence à sequência de Fibonacci.\n", num);
    }

    return 0;
}