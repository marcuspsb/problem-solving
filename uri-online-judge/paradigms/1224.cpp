// https://www.urionlinejudge.com.br/judge/pt/problems/view/1224

#include <bits/stdc++.h>

using namespace std;

int readInt () 
{
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main()
{
	int N, i, tam, v[10000];
	long long M[10000][2];
	while(scanf("%d", &N) != EOF)
	{
		for(i=0;i<N;i++) v[i] = readInt();// scanf("%d", &v[i]);
		tam = 2;
		bool ant = 0;
		for(i=0;i<=N-tam;i++) M[i][ant] = max(v[i], v[i+1]);
		while(tam != N)
		{
			tam += 2;
			ant = !ant;
			for(i=0;i<=N-tam;i++) M[i][ant] = max(v[i] + min(M[i+2][!ant], M[i+1][!ant]), v[i+tam-1] + min(M[i][!ant], M[i+1][!ant]));
		}
		printf("%lld\n", M[0][ant]);
	}
	return 0;
}