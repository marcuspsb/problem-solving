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

const int MAXN = 10e4 + 10;
int tt, n, m;
vector<ii> V;

int bs(int goal, int size, int lo) {
  int hi = n;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;
    if (V[mi].F == goal)
      return V[mi].S;
    else if (V[mi].F > goal)
      hi = mi - 1;
    else
      lo = mi + 1;
  }
  return -1;
}

int main() {
  int x;

  scanf("%d", &tt);
  while (tt--) {
    scanf("%d %d", &m, &n);

    rep(i, 0, n) {
      scanf("%d", &x);
      V.pb(ii(x, i + 1));
    }
    sort(V.begin(), V.end());
    rep(i, 0, n) {
      int ret = bs(m - V[i].F, n, i + 1);
      if (-1 != ret) {
        printf("%d %d\n", min(V[i].S, ret), max(V[i].S, ret));
        break;
      }
    }
    V.clear();
  }
  return 0;
}