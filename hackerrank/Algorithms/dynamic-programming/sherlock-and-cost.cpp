// https://www.hackerrank.com/challenges/sherlock-and-cost/problem

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

const int MAXN = 10e5+10;
int V[MAXN];
int pd[MAXN][2];
int tt, n;

int solve(int pos, bool f) {
  if (pos == n) return 0;
  if (-1 != pd[pos][f]) return pd[pos][f];

  int ant = (f) ? V[pos-1] : 1;
  int r1 = solve(pos+1, true) + abs(V[pos] - ant);
  int r2 = solve(pos+1, false) + abs(1 - ant);

  return pd[pos][f] = max(r1,r2);
}

int main(){

  scanf("%d", &tt);
  while(tt--) {
    scanf("%d", &n);
    memset(pd, -1, sizeof(pd));
    rep(i,0,n) scanf("%d", &V[i]);
    int ans = max(solve(1,true),solve(1,false));
    printf("%d\n",ans);
  }
  return 0;
}