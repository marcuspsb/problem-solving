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
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

const int MAXN = 10e5 + 10;
int nv, ne, clib, croad;
vector<int> ladj[MAXN];
bool vis[MAXN];

ll dfs(int u) {
  if (vis[u]) return 0;
  vis[u] = true;

  ll ret = 1;
  rep(i, 0, ladj[u].size()) {
    int v = ladj[u][i];
    if (!vis[v]) {
      ret += dfs(v);
    }
  }
  return ret;
}

int main() {
  int tt, v, u;
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d %d %d", &nv, &ne, &clib, &croad);
    rep(i, 0, ne) {
      scanf("%d %d", &u, &v);
      ladj[u].pb(v);
      ladj[v].pb(u);
    }
    ll ans = 0;
    rep(i, 1, nv + 1) {
      if (!vis[i]) {
        ll ret = dfs(i);
        ans += min(ret * clib, clib + (croad * (ret - 1)));
      }
    }
    printf("%lld\n", ans);
    rep(i, 0, nv + 1) {
      ladj[i].clear();
      vis[i] = false;
    }
  }
  return 0;
}