// https://www.hackerrank.com/challenges/bfsshortreach/problem

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c) \
  sort(all(c));   \
  (c).resize(unique(all(c)) - c.begin());

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

const int MAXN = 10e3 + 5;
int N, M;
vector<int> ladj[MAXN];
int dis[MAXN];
bool vis[MAXN];

void bfs(int s) {
  rep(i, 1, N + 1) dis[i] = INF;
  priority_queue<ii> Q;
  Q.push(ii(0, s));
  while (!Q.empty()) {
    int d = -Q.top().F;
    int u = Q.top().S;
    Q.pop();
    if (dis[u] < INF) continue;
    dis[u] = d;
    rep(i, 0, ladj[u].size()) {
      int v = ladj[u][i];
      Q.push(ii(-(d + 1), v));
    }
  }
  bool f = false;
  rep(i, 1, N + 1) {
    if (i == s) continue;
    if (f) printf(" ");
    printf("%d", (dis[i] == INF) ? -1 : 6 * dis[i]);
    f = true;
  }
  printf("\n");
  return;
}

int main() {
  int tt, u, v, s;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &N, &M);
    rep(i, 0, M) {
      scanf("%d %d", &u, &v);
      ladj[u].pb(v);
      ladj[v].pb(u);
    }
    scanf("%d", &s);
    bfs(s);
    rep(i, 1, N + 1) ladj[i].clear();
  }
  return 0;
}