// https://www.urionlinejudge.com.br/judge/pt/problems/view/1522

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define sd(x) scanf("%d", &x)
#define ss(x) scanf("%s", x)

typedef pair<int, int> ii;
typedef long long ll;

char alpha[] = "";
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int pd[101][101][101];
int v1[101], v2[101], v3[101];
bool f;
int N;
bool pode(int a, int b, int c)
{
    return ((a + b + c) % 3 == 0);
}

bool solve(int a, int b, int c)
{
    if ((a == N && b == N && c == N) || f)
        return 1;
    if (pd[a][b][c] != -1)
        return pd[a][b][c];

    bool ret = 0;
    /*pegando uma carta*/
    if (a < N && pode(v1[a], 0, 0))
        ret += solve(a + 1, b, c);
    if (b < N && pode(0, v2[b], 0))
        ret += solve(a, b + 1, c);
    if (c < N && pode(0, 0, v3[c]))
        ret += solve(a, b, c + 1);

    /*pegando duas cartas*/
    if (a < N && b < N && pode(v1[a], v2[b], 0))
        ret += solve(a + 1, b + 1, c);
    if (a < N && c < N && pode(v1[a], 0, v3[c]))
        ret += solve(a + 1, b, c + 1);
    if (b < N && c < N && pode(0, v2[b], v3[c]))
        ret += solve(a, b + 1, c + 1);

    /*pegando tres cartas*/
    if (a < N && b < N && c < N && pode(v1[a], v2[b], v3[c]))
        ret += solve(a + 1, b + 1, c + 1);

    return pd[a][b][c] = ret;
}

int main()
{
    while (sd(N) && N)
    {
        rep(i, 0, N)
            sd(v1[i]),
            sd(v2[i]), sd(v3[i]);
        memset(pd, -1, sizeof(pd));

        printf("%d\n", solve(0, 0, 0));
    }

    return 0;
}