#include <bits/stdc++.h>

using namespace std;

int check(int total, int p0, int s, int t) {

  int count = 0, d;
  while (total--) {
    cin >> d;
    int p = p0 + d;
    if (p >= s && p <= t)
      count++;
  }
  return count;
}
int main() {
  int s, t, a, b, m, n;
  cin >> s >> t >> a >> b >> m >> n;
  cout << check(m, a, s, t) << endl;
  cout << check(n, b, s, t) << endl;
  return 0;
}