/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int INDICE = 13;
   int SOMA = 0;
   int K = 0;
   
   while (K > INDICE) {
       K = K + 1;
       SOMA = SOMA + K;
   }
   
   printf("O valor da variavel SOMA é %d\n", SOMA);

    return 0;
}