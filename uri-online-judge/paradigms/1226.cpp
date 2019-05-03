// https://www.urionlinejudge.com.br/judge/pt/problems/view/1226

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull N;
ull pd[20][2][2];
bool memo[20][2][2];
vector<int> V;
void getV(ull x){
    V.clear();
    while(x){
        V.push_back(x%10);
        x/=10;
    }
    reverse(V.begin(),V.end());
}
ull solve(int pos, bool f, bool um){
    if(pos == V.size()) return 1;
    if(memo[pos][f][um]) return pd[pos][f][um];
    ull ret = 0;
    if(f){
        for(int i = 0; i < V[pos] ; i++){
            if((um && i == 3) || i == 4) continue;
            ret += solve(pos+1,0,(i==1));
        }
        if(V[pos] != 4 && !(um && V[pos] == 3))
            ret += solve(pos+1, true, (V[pos]==1));

    } else {
        for(int i = 0; i <= 9; i++){
            if((um && i==3) || i == 4) continue;
            ret += solve(pos+1, false, (i==1));
        }
    }
    memo[pos][f][um] = true;
    return pd[pos][f][um] = ret;

}

int main() {

    while(cin >> N){
            ull lo = 0, hi = 0;
            hi--;
            ull mi;
            while(lo <= hi){
                memset(memo,0,sizeof(memo));
                mi = lo+(hi-lo)/2;
                getV(mi);
                ull r = solve(0,1,0)-1;
                if(r >= N) hi = mi-1;
                else if(r < N) lo = mi+1;

            }
            cout << lo << endl;
    }
    return 0;

}
