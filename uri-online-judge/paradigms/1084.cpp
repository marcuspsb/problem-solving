// https://www.urionlinejudge.com.br/judge/pt/problems/view/1084
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int busca(char x, char *v, int inicio, int fim)
{
    int meio;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (v[meio] < x)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return inicio;
}

int main()
{

    int n, apg, aux2, x;
    char *num, *aux;

    while (scanf("%d%d", &n, &apg) && n + apg)
    {
        num = (char *)malloc((n + 1) * sizeof(char));
        scanf("%s", num);
        aux = (char *)calloc(n - apg + 1, sizeof(char));
        aux[0] = num[0];
        aux2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (i <= apg)
                x = busca(num[i], aux, 0, aux2);
            else
                x = busca(num[i], aux, i - apg, aux2);

            if (x < n - apg)
            {
                aux2 = x;
                aux[x] = num[i];
            }
        }
        aux[n - apg] = '\0';
        printf("%s\n", aux);
        free(num);
        free(aux);
    }

    return 0;
}
