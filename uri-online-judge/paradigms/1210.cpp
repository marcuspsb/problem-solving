// https://www.urionlinejudge.com.br/judge/pt/problems/view/1210

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define tr(it, s) for (typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define pb push_back
#define clr(a) memset((a), 0, sizeof(a))
#define pi 3.1415926535897932384626433832795028841971

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, I, M, P, p;
int v1[2005];  // custo manuten??o
int v2[2005];  // lucro venda
int pd[2005][2005];
bool memo[2005][2005];
bool primeiro;

int readInt() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}

int solve(int a, int b)  // ano atual, ano eqp
{
  if (a == N) return 0;
  if (pd[a][b] != -1) return pd[a][b];
  int r, r1, r2;
  r = r1 = r2 = INF;
  if (b == M)
    r2 = solve(a + 1, 1) + P - v2[b] + v1[0];
  else {
    r1 = solve(a + 1, b + 1) + v1[b];  // dar manuten??o
    if (b) r2 = solve(a + 1, 1) + P - v2[b] + v1[0];
  }
  if (r2 <= r1) {
    pd[a][b] = r2;
    memo[a][b] = 1;
  } else {
    pd[a][b] = r1;
  }

  return pd[a][b];
}

void backing_track(int a, int b) {
  if (a == N) return;
  if (memo[a][b]) {
    if (!primeiro) printf(" ");
    primeiro = 0;
    a++;
    printf("%d", a);
    backing_track(a, 1);
  } else
    backing_track(a + 1, b + 1);
}

int main() {
  while (scanf("%d%d%d%d", &N, &I, &M, &P) != EOF) {
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= M; j++) {
        pd[i][j] = -1;
        memo[i][j] = 0;
      }

    for (int i = 0; i < M; i++) scanf("%d", &v1[i]);  // v1[i] = readInt();
    v1[M] = 0;
    v2[0] = -INF;
    for (int i = 1; i <= M; i++) scanf("%d", &v2[i]);  // v2[i] = readInt();

    printf("%d\n", solve(0, I));
    primeiro = 1;
    backing_track(0, I);
    if (primeiro) printf("0");
    printf("\n");
  }

  return 0;
}