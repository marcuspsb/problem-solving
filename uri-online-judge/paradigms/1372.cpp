// https://www.urionlinejudge.com.br/judge/pt/problems/view/1372
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define MAXN 100005

int N, M;
int v1[MAXN], v2[MAXN];
int lim;
int pd[MAXN];
int *vet;

int solve(int a) {
  if (a >= lim) return 0;
  if (pd[a] != -1) return pd[a];
  return pd[a] = max(solve(a + 1), solve(a + 2) + vet[a]);
}

int main() {
  while (scanf("%d%d", &N, &M) && N + M) {
    lim = M;
    rep(i, 0, N) {
      memset(pd, -1, sizeof(int) * M);
      rep(j, 0, M) { scanf("%d", &v1[j]); }
      vet = &v1[0];

      v2[i] = solve(0);
    }
    memset(pd, -1, sizeof(int) * N);
    lim = N;
    vet = &v2[0];
    printf("%d\n", solve(0));
  }

  return 0;
}