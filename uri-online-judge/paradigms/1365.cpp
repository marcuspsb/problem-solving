// https://www.urionlinejudge.com.br/judge/pt/problems/view/1365
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3fffffff

int N, M, K;
int dp[301];
int grid[301][301];

int max2D() {
  int res = INF;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) dp[j] = 0;
    for (int k = i; k < M; k++) {
      for (int j = 0; j < N; j++) {
        dp[j] += grid[k][j];
      }

      int temp = 0;
      int *pt1 = &dp[0];
      int *pt2 = &dp[0];
      int x1 = 0;
      int j = 0;
      bool f = true;

      while (pt2 != &dp[N]) {
        if (f) temp += *pt2;

        if (temp >= K) {
          res = min(res, ((k - i) + 1) * ((j - x1) + 1));
          temp -= *pt1;
          pt1++;
          x1++;
          f = false;
        } else {
          f = true;
          pt2++;
          j++;
        }
      }
    }
  }
  return res;
}

main() {
  char c;
  while (scanf("%d %d %d", &M, &N, &K) && N + M + K) {
    int ans = INF;
    for (int p = 0; p < M; p++) {
      for (int q = 0; q < N; q++) {
        scanf(" %c", &c);
        grid[p][q] = (c == '.');
      }
    }
    cout << max2D() << endl;
  }
}
