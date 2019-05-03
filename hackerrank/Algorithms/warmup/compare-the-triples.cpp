// https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout<<__LINE__<<": "<<#x<<" = "<<x<<endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c) sort(all(c)); (c).resize(unique(all(c))-c.begin());

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS){
    return ((x <= y+tol) ? (x+tol < y) ? -1:0:1); }

int main(){
    int alice[3], bob[3];
    rep(i,0,3) cin >> alice[i];
    rep(i,0,3) cin >> bob[i];

    int a = 0, b = 0;
    rep(i,0,3) {
      a += alice[i] > bob[i];
      b += bob[i] > alice[i];
    }
    cout << a << " " << b << endl;
    return 0;
}