// https://www.hackerrank.com/challenges/simple-array-sum/problem

#include <bits/stdc++.h>

using namespace std;

int simpleArraySum(int n, vector <int> ar) {
    int ret = 0;
    for(int i = 0; i < ar.size(); ++i) ret += ar[i];
    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = simpleArraySum(n, ar);
    cout << result << endl;
    return 0;
}