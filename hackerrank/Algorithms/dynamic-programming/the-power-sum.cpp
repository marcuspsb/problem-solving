// https://www.hackerrank.com/challenges/the-power-sum/problem

#include <bits/stdc++.h>

using namespace std;

int X, N;
int ans = 0;
int maxBase;

long long pd[101][1010];

long long solve(int base, int sum) {
  if (sum == X) {
    return 1;
  }

  if (sum > X || base == maxBase) {
    return 0;
  }

  if (pd[base][sum] != -1)
    return pd[base][sum];

  long long ret = 0;
  ret += solve(base + 1, pow(base, N) + sum);
  ret += solve(base + 1, sum);

  return pd[base][sum] = ret;
}

int main() {

  cin >> X >> N;
  maxBase = pow(X, (1.0 / N)) + 1;
  memset(pd, -1, sizeof(pd));

  // time_t t0,t1;

  // t0 = time(NULL);
  // cout << " ------ " << t0 << endl;
  cout << solve(1, 0) << endl;
  // t1 = time(NULL);
  // cout << t1 - t0 << endl;
  return 0;
}