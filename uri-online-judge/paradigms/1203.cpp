// https://www.urionlinejudge.com.br/judge/pt/problems/view/1203
#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define clr(a) memset((a), 0, sizeof(a))
#define PI acos(-1.0)
#define MAX_N 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;

int R, K;
int vet[102];
bool vis[10000];

int main() {
  int a, b;
  while (scanf("%d%d", &R, &K) != EOF) {
    memset(vet, 0, sizeof vet);
    memset(vis, false, sizeof vis);
    int t = 0;
    for (int i = 0; i < K; i++) {
      scanf("%d%d", &a, &b);
      vet[a]++;
      vet[b]++;
      t += 2;
    }
    vis[0] = 1;
    for (int i = 1; i <= R; i++) {
      // if(!vet[i]) continue;
      for (int j = t; j >= 0; j--) {
        if (vis[j] == 1) {
          vis[j + vet[i]] = 1;
        }
      }
    }
    printf("%c\n", (vis[K]) ? 'S' : 'N');
  }

  return 0;
}