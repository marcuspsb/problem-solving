// https://www.urionlinejudge.com.br/judge/pt/problems/view/1494

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

int V[10], qPar, qImpar;

ll pd[11][11][60];

ll C[110][110];

ll solve(int pos, int diff, int par, int impar) {
  if (pos > 9) return (diff == 0);
  if (pd[pos][diff][par] != -1) return pd[pos][diff][par];

  ll ret = 0;
  for (int i = 0; i <= V[pos]; i++) {
    if (i <= par && (V[pos] - i) <= impar) {
      int d = diff;
      d += (i * pos) % 11, d %= 11;
      d -= ((V[pos] - i) * pos) % 11, d += 11, d %= 11;
      ll aux = solve(pos + 1, d, par - i, impar - (V[pos] - i)) % mod;
      aux = (aux * C[par][i]) % mod;
      aux = (aux * C[impar][V[pos] - i]) % mod;
      ret = (ret + aux) % mod;
      //          ret = ((ret + (aux*C[par][i])%mod)*C[impar][V[pos]-i])%mod;
    }
  }
  return pd[pos][diff][par] = ret;
}

int main() {
  for (int i = 0; i < 105; i++) C[i][0] = 1, C[i][i] = 1;
  for (int i = 1; i < 105; i++)
    for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

  string s;
  while (cin >> s) {
    qPar = s.size() / 2;
    if (s.size() & 1) qPar++;
    qImpar = s.size() / 2;
    for (int i = 0; i < 10; i++) V[i] = 0;
    for (int i = 0; i < s.size(); i++) V[s[i] - '0']++;

    ll ans = 0;

    for (int i = 1; i <= 9; i++) {
      if (V[i] == 0) continue;
      V[i]--;
      memset(pd, -1, sizeof(pd));
      ans = (ans + solve(0, i, qPar - 1, qImpar)) % mod;
      V[i]++;
    }
    cout << ans << "\n";
  }

  return 0;
}