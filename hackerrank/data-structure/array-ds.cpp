// https://www.hackerrank.com/challenges/arrays-ds/problem

#include <bits/stdc++.h>

using namespace std;

int main(){

  int N,X;
  vector<int> vet;

  cin >> N;
  while(N--){
    cin >> X;
    vet.push_back(X);
  }
  for(int i = vet.size() - 1; i >= 0; --i) cout << vet[i] << " ";

  return 0;
}
