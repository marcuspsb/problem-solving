// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

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

const int MAXN = 10e4+5;
int N, M, pset[MAXN], ranki[MAXN], size[MAXN];

typedef pair< int , ii > edge;
vector<edge> E;

bool compare(const edge &a, const edge& b) {
  if(a.F > b.F) return false;
  else if(a.F < b.F) return true;
  else return (a.F + a.S.F + a.S.S) < (b.F + b.S.F + b.S.S);
}

int findset(int x) {
  if( x != pset[x])
    pset[x] = findset(pset[x]);
  return pset[x];
}

void unionSet(int u, int v) {
  u = findset(u); v = findset(v);
  if(u == v) return;
  if(ranki[u] > ranki[v])
    pset[v] = u;
  else
    pset[u] = v;
}

bool sameset(int u, int v) {
  return findset(u) == findset(v);
}

int main(){
  int u,v,w;
  scanf("%d %d",&N, &M);
  rep(i,0,M) {
    scanf("%d %d %d", &u, &v, &w);
    E.pb(edge(w,ii(u,v)));
    E.pb(edge(w,ii(v,u)));
  }
  sort(E.begin(), E.end(), compare);
  rep(i,1,N+1) {
    pset[i] = i;
    ranki[i] = 0;
  }
  ll ans = 0;
  rep(i,0,E.size()) {
    w = E[i].F;
    u = E[i].S.F;
    v = E[i].S.S;

    if(!sameset(u,v)) {
      unionSet(u,v);
      ans += w;
    }
  }
  printf("%lld\n",ans);
  return 0;
}