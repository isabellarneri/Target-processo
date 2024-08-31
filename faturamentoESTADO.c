#include <stdio.h>

int main() {
    // Valores de faturamento por estado
    double faturamento_sp = 67836.43;
    double faturamento_rj = 36678.66;
    double faturamento_mg = 29229.88;
    double faturamento_es = 27165.48;
    double faturamento_outros = 19849.53;

    // Cálculo do faturamento total
    double faturamento_total = faturamento_sp + faturamento_rj + faturamento_mg + faturamento_es + faturamento_outros;

    // Cálculo dos percentuais
    double percentual_sp = (faturamento_sp / faturamento_total) * 100;
    double percentual_rj = (faturamento_rj / faturamento_total) * 100;
    double percentual_mg = (faturamento_mg / faturamento_total) * 100;
    double percentual_es = (faturamento_es / faturamento_total) * 100;
    double percentual_outros = (faturamento_outros / faturamento_total) * 100;

    // Impressão dos resultados
    printf("Percentual de representação de cada estado:\n");
    printf("SP: %.2f%%\n", percentual_sp);
    printf("RJ: %.2f%%\n", percentual_rj);
    printf("MG: %.2f%%\n", percentual_mg);
    printf("ES: %.2f%%\n", percentual_es);
    printf("Outros: %.2f%%\n", percentual_outros);

    return 0;
}