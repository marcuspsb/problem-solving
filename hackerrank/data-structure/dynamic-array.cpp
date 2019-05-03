// https://www.hackerrank.com/challenges/dynamic-array/problem

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10e5+5;

vector<int> V[MAXN];

int main(){

  int N,Q,q,a,b,LA=0;

  cin >> N >> Q;

  while(Q--){
    cin >> q >> a >> b;
    int seq = (a ^ LA) % N;
    if(q == 1){
      V[ seq ].push_back(b);
    } else {
      LA = V[ seq ][ b % V[seq].size()];
      cout << LA << endl;
    }
  }

  return 0;
}
