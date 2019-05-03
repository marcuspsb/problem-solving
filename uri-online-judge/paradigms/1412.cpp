// https://www.urionlinejudge.com.br/judge/pt/problems/view/1412

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                            \
  {                                                          \
        sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() ); \
  }
#define pb push_back
#define sz size()
#define D(x) \
  if (1) cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
  vector<int> v;
  string str;

  while (cin >> str) {
    if (str[0] == '*') break;

    v.pb((str[0] - 'a' + 26) % 26);
    rep(i, 1, str.size()) v.pb((str[i] - str[i - 1] + 26) % 26);
    v.pb(('a' - str[str.size() - 1] + 26) % 26);

    sort(v.begin(), v.end());

    int i = 0, j = v.size() - 1, ans = 0;
    while (i < j) {
      int id = v[i];
      int jd = 26 - v[j];
      if (id == jd) {
        ans += id;
        i++;
        j--;
        continue;
      }

      if (id < jd) {
        ans += id;
        v[j] = (v[j] + id) % 26;
        i++;
      } else {
        ans += jd;
        v[i] = (v[i] - jd + 26) % 26;
        j--;
      }
    }
    printf("%d\n", ans);
    v.clear();
  }

  return 0;
}