#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
vector<ii> blockers;
int minList[10] = {0};
ii points[10];

enum pos { q1 = 0, q2, q3, q4, yu, yd, xr, xl };

void initializeList(int N, int qx, int qy) {
  minList[q1] = min(qx - 1, N - qy);
  minList[q2] = min(qx - 1, qy - 1);
  minList[q3] = min(N - qx, qy - 1);
  minList[q4] = min(N - qx, N - qy);
  minList[yu] = qx - 1;
  minList[yd] = N - qx;
  minList[xr] = N - qy;
  minList[xl] = qy - 1;
}

int main() {
  int N, Q, x, y, qx, qy;

  cin >> N >> Q;
  cin >> qx >> qy;
  while (Q--) {
    cin >> x >> y;
    blockers.push_back(ii(x, y));
  }

  initializeList(N, qx, qy);

  for (int i = 0; i < blockers.size(); ++i) {
    x = blockers[i].first;
    y = blockers[i].second;

    if (abs(qx - x) == abs(qy - y)) {
      int dis = abs(qx - x) - 1;
      if (x > qx) {
        if (y > qy) {
          points[q4] = ii(x, y);
          minList[q4] = min(minList[q4], dis);
        } else if (qy > y) {
          points[q3] = ii(x, y);
          minList[q3] = min(minList[q3], dis);
        }
      } else if (x < qx) {
        if (y > qy) {
          points[q1] = ii(x, y);
          minList[q1] = min(minList[q1], dis);
        } else if (qy > y) {
          points[q2] = ii(x, y);
          minList[q2] = min(minList[q2], dis);
        }
      }
    }

    if (x == qx) {
      if (y > qy) {
        points[xr] = ii(x, y);
        minList[xr] = min(minList[xr], y - qy - 1);
      } else {
        points[xl] = ii(x, y);
        minList[xl] = min(minList[xl], qy - y - 1);
      }
    }

    if (y == qy) {
      if (x > qx) {
        points[yd] = ii(x, y);
        minList[yd] = min(minList[yd], x - qx - 1);
      } else {
        points[yu] = ii(x, y);
        minList[yu] = min(minList[yu], qx - x - 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    ans += minList[i];
  }
  cout << ans << endl;

  return 0;
}
