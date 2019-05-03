// https://www.hackerrank.com/challenges/coin-change/problem

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;

const int MAXM = 55;
const int MAXN = 255;
int coins[MAXM], N, M;
ll pd[MAXN][MAXM];

ll solve(int sum, int pos) {
  if (sum < 0 || pos == M)
    return 0;
  if (sum == 0)
    return 1;
  if (-1 != pd[sum][pos])
    return pd[sum][pos];
  ll ret = 0;
  ret += solve(sum - coins[pos], pos);
  ret += solve(sum, pos + 1);

  return pd[sum][pos] = ret;
}

int main() {
  scanf("%d %d", &N, &M);
  rep(i, 0, M) scanf("%d", &coins[i]);
  memset(pd, -1, sizeof(pd));
  printf("%lld\n", solve(N, 0));
  return 0;
}