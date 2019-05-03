// https://www.urionlinejudge.com.br/judge/pt/problems/view/1286
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int matriz[100][100];

int mochila(int v[], int w[], int pTotal, int qObj)
{
    for (int i = 0; i <= pTotal; i++)
        matriz[0][i] = 0;

    for (int j = 1; j <= qObj; j++)
    {
        for (int k = 1; k <= pTotal; k++)
        {
            if (w[j] > k)
            {
                matriz[j][k] = matriz[j - 1][k];
            }
            else if (matriz[j - 1][k - w[j]] + v[j] > matriz[j - 1][k])
                matriz[j][k] = matriz[j - 1][k - w[j]] + v[j];
            else
                matriz[j][k] = matriz[j - 1][k];
        }
    }
    return matriz[qObj][pTotal];
}

int main() {
    int v[100], w[100], pTotal, qObj;

    while (scanf("%d", &qObj) && qObj) {
        scanf("%d", &pTotal);
        for (int i = 1; i <= qObj; i++)
            scanf("%d%d", &v[i], &w[i]);
        printf("%d min.\n", mochila(v, w, pTotal, qObj));
    }
    return 0;
}