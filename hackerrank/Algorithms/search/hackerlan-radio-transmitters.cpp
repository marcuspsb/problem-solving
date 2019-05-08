// https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c)                                                              \
  sort(all(c));                                                                \
  (c).resize(unique(all(c)) - c.begin());

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

const int MAXN = 10e4 + 10;

int dx[4] = {-1, 1, -1, 1};
int dy[4] = {1, 1, -1, -1};

int main() {

  vector<int> P;
  unordered_map<int, int> posMap;
  int N, X, v;
  cin >> N >> X;
  rep(i, 0, N) {
    cin >> v;
    posMap[v] = i;
    P.pb(v);
  }
  sort(all(P));

  int ans, left, right, mid, perfectPosition, covarage;
  ans = covarage = 0;

  while (covarage < P[N-1]) {
    int mostLeftHouseIdx = upper_bound(P.begin(), P.end(), covarage) - P.begin();

    perfectPosition = P[mostLeftHouseIdx] + X;
    left = 0; right = N;

    while (left + 1 < right) {
      mid = (left + right) / 2;
      if (P[mid] == perfectPosition) {
        left = mid;
        break;
      } else if (P[mid] > perfectPosition) {
        right = mid;
      } else {
        left = mid;
      }
    }
    covarage = P[left] + X;
    ans++;
  }

  cout << ans << endl;

  return 0;
}

/*
8 2
2 4 5 6 7 9 11 12

7 2
2 4 5 6 9 12 15
0 1 2 3 4  5  6

*/