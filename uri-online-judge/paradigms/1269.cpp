// https://www.urionlinejudge.com.br/judge/pt/problems/view/1269

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
//#define F first
//#define S second
#define sd(x) scanf("%d", &x)
#define ss(x) scanf("%s", x)
#define MAXN 1010

typedef pair<int, int> ii;
typedef long long ll;

char alpha[] = "";
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

int T, E;

vector<int> ladj[MAXN];
vector<int> empreg[MAXN];

int vis[MAXN], peso[MAXN], ans[MAXN];
int QV;
int topo[MAXN];

int dfs(int u) {
  if (vis[u]) return peso[u];
  vis[u] = true;
  int ret = 0;
  rep(i, 0, ladj[u].size()) {
    int w = ladj[u][i];
    ret += dfs(w);
  }
  topo[u] = QV--;
  return peso[u] += ret;
}

void dfs2(int u) {
  if (vis[u]) return;
  vis[u] = true;

  rep(i, 0, ladj[u].size()) dfs2(ladj[u][i]);
}

bool cmp(const int a, const int b) { return topo[a] < topo[b]; }

int main() {
  int V, A, QE, v, emp;
  while (scanf("%d%d", &T, &E) && T | E) {
    QV = T;
    int MA = max(T, E) + 1;
    rep(i, 1, MA) vis[i] = 0;
    rep(u, 1, T + 1)  // tarefa mais dependente
    {
      scanf("%d%d%d", &V, &A,
            &QE);  // valor, quantidade de ligações e quantidade de empregados
      peso[u] = V;  // tarefa u tem peso V
      rep(i, 1, A + 1) {
        scanf("%d", &v);  // tarefa menos dependente u -> w
        ladj[u].pb(v);
      }
      rep(j, 1, QE + 1) {
        scanf("%d", &emp);
        empreg[emp].pb(u);  // trabalhador emp recebe a trafera u
      }
    }
    rep(i, 1, T + 1) if (!vis[i]) dfs(i);

    rep(i, 1, MA) vis[i] = ans[i] = 0;

    rep(i, 1, E + 1) {
      rep(j, 0, T + 1) vis[j] = 0;
      sort(empreg[i].begin(), empreg[i].end(), cmp);

      rep(j, 0, empreg[i].size()) {
        if (!vis[empreg[i][j]]) {  // !vis[ j ]
          ans[i] += peso[empreg[i][j]];
          dfs2(empreg[i][j]);
        }
      }
    }

    printf("*****\n");
    rep(i, 1, E + 1) printf("%d %d\n", i, ans[i]);

    rep(i, 1, MA) ladj[i].clear(), empreg[i].clear();
  }

  return 0;
}