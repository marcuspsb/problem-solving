// https://www.urionlinejudge.com.br/judge/pt/problems/view/1475
#include <bits/stdc++.h>
using namespace std;
#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)

int N, C, T1, T2, dp[1111], x[1111];

int BuscaBinaria(int chave)
{
    int inf, sup, meio;
    inf = 0;
    sup = N - 1;
    while (inf <= sup)
    {
        meio = (inf + sup) / 2;
        if (chave == x[meio])
        {
            cout << x[meio] << "-" << x[meio + 1] << endl;
            return meio;
        }
        else if (chave < x[meio])
            sup = meio - 1;
        else
            inf = meio + 1;
    }
    cout << x[meio] << " " << x[meio + 1] << endl;
    if (N % 2 == 0)
        return meio; /* n?o encontrado */
    else
        return meio + 1;
}

int go(int i)
{

    if (i >= N)
        return 0; //dp[i] = 0;

    if (dp[i] != -1)
        return dp[i];

    int l1 = upper_bound(x + i, x + N, x[i] + T1) - x;
    //printf("l1 = %d - upper_bound(%d+%d,%d+%d,%d+%d) - %d\n",x[l1],x,i,x,N,x[i],T1,x);
    int l2 = upper_bound(x + i, x + N, x[i] + T2) - x;
    //printf("l2 = %d - upper_bound(%d+%d,%d+%d,%d+%d) - %d\n",x[l2],x,i,x,N,x[i],T2,x);

    int ans = min(T1 + go(l1), T2 + go(l2));
    dp[i] = ans;
    return ans;
}

int main()
{
    while (scanf("%d%d%d%d", &N, &C, &T1, &T2) != EOF)
    {
        rp(i, N) scanf("%d", &x[i]);
        sort(x, x + N);
        memset(dp, -1, sizeof dp);
        printf("%d\n", go(0));
    }
    return 0;
}