// https://www.urionlinejudge.com.br/judge/pt/problems/view/1034

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3fffffff

int r, m, n, bloco, pd[1000000];

int main()
{

    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
            pd[i] = INF;
        pd[0] = 0;
        for (int j = 0; j < n; j++)
        {

            scanf("%d", &bloco);
            pd[bloco] = 1;
            for (int i = bloco + 1; i <= m; i++)
            {
                pd[i] = min(pd[i], pd[i - bloco] + 1);
            }
        }
        cout << pd[m] << endl;
    }

    return (0);
}