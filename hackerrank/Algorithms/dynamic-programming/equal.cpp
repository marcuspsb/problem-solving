// https://www.hackerrank.com/challenges/equal/problem

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

int calc(int n, vector<int> &V) {
  int ret = 0;
  rep(i, 0, V.size()) {
    int a = V[i] - n;
    ret += (a / 5) + (a % 5) / 2 + (a % 5) % 2;
  }
  return ret;
}

int main() {
  int tt, n;

  scanf("%d", &tt);
  while (tt--) {
    scanf("%d", &n);
    vector<int> V(n);
    rep(i, 0, n) scanf("%d", &V[i]);
    sort(V.begin(), V.end());
    int ans = INF;
    rep(i, 0, 5) ans = min(ans, calc(V[0] - i, V));
    printf("%d\n", ans);
  }
  return 0;
}