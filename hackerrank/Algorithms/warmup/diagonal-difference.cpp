#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout<<__LINE__<<": "<<#x<<" = "<<x<<endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c) sort(all(c)); (c).resize(unique(all(c))-c.begin());

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS){
    return ((x <= y+tol) ? (x+tol < y) ? -1:0:1); }

int main() {
  int n, dp, ds, x;
  dp = ds = 0;
  cin >> n;
  rep(i,0,n)
    rep(j,0,n) {
      cin >> x;
      if(i == j) dp += x;
      if(i + j == n-1) ds += x;
    }
   cout << abs(dp - ds);
   return 0;
}
