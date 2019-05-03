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
typedef pair<ll, int> li;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

const int MAXN = 10e4 + 10;
int N;
vector<li> V;

int main() {
  ll x;

  scanf("%d", &N);
  rep(i, 0, N) {
    scanf("%lld", &x);
    V.pb(li(x, i));
  }
  sort(V.begin(), V.end());
  ll ans = (1ULL << 63) - 1, diff;

  rep(i, 0, N - 1) {
    rep(j, i + 1, N) {
      if (V[i].S > V[j].S && V[i].F != V[j].F) {
        diff = V[j].F - V[i].F;
        ans = min(ans, diff);
        break;
      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}