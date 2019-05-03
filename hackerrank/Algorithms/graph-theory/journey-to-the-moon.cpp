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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS){
    return ((x <= y+tol) ? (x+tol < y) ? -1:0:1); }

const int MAXN = 10e5+5;
int N, M;
vector<int> ladj[MAXN];
bool vis[MAXN];

int dfs(int u) {
  if(vis[u]) return 0;
  vis[u] = true;

  int ret = 1;
  rep(i,0,ladj[u].size()){
    int v = ladj[u][i];
    if( !vis[v] ) ret += dfs(v);
  }
  return ret;
}

int main(){
  int u,v;

  scanf("%d %d", &N, &M);
  rep(i,0,M) {
    scanf("%d %d",&u, &v);
    ladj[u].pb(v);
    ladj[v].pb(u);
  }
  memset(vis, 0 ,sizeof(vis));

  ull ans = 0;
  ull sum = 0;
  rep(i,0,N) {
    if( !vis[i] ) {
      ull ret = dfs(i);
      ans += ret * sum;
      sum += ret;
    }
  }
  cout << ans << endl;
  return 0;
}