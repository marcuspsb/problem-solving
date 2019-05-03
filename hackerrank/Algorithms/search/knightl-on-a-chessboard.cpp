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
typedef pair< int, ii > pii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int MAXN = 10e4+10;

int dx[4] = {-1, 1,-1, 1};
int dy[4] = { 1, 1,-1,-1};

int N;
bool vis[26][26];

bool isPossible(int x, int y) {
  return (x >= 0 && x < N && y >= 0 && y < N && !vis[x][y]);
}

int bfs(int a, int b) {

  memset(vis,false,sizeof(vis));
  priority_queue<pii> Q;

  Q.push(pii(0,ii(0,0)));
  while(!Q.empty()) {
    int d = -Q.top().F, x = Q.top().S.F, y = Q.top().S.S;
    Q.pop();
    if(x == N-1 && y == N-1) return d;
    if( vis[x][y] ) continue;
    vis[x][y] = true;
    rep(i,0,4) {
      int xx = x + (dx[i] * a);
      int yy = y + (dy[i] * b);
      if( isPossible(xx, yy) ) {
        Q.push( pii(-(d+1),ii(xx,yy)));
      }
      if( isPossible(yy, xx) ) {
        Q.push( pii(-(d+1),ii(yy,xx)));
      }
    }
  }
  return -1;
}

int main(){
  scanf("%d",&N);
  rep(i,1,N) {
    rep(j,1,N) {
      if(j > 1) printf(" ");
      printf("%d",bfs(i,j));
    }
    printf("\n");
  }

  return 0;
}