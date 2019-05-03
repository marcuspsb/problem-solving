#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, X;

  cin >> N;
  while (N--) {
    cin >> X;
    if (X < 38) {
      cout << X << endl;
    } else {
      int rest = X % 5;
      if (rest > 2) {
        cout << X + (5 - rest) << endl;
      } else {
        cout << X << endl;
      }
    }
  }

  return 0;
}