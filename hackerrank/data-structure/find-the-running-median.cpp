// https://www.hackerrank.com/challenges/find-the-running-median/problem

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef unsigned long long llu;

#define INF 0x3f3f3f3f
#define rf freopen("in.txt", "r", stdin)
#define wf freopen("out.txt", "w", stdout)
#define debug(x) cerr << #x << " " << x << endl;
#define f first
#define s second
#define mp make_pair
#define pb push_back

struct compare{
    bool operator()(int a, int b) {
        return a > b;
    }
};

priority_queue<int> max_heap;
priority_queue<int, vector<int>, compare> min_heap;

void addNumber(int num) {
    if (max_heap.empty()) {
        max_heap.push(num);
    } else if (min_heap.empty()) {
        int max_top = max_heap.top();
        if (max_top > num ) {
            max_heap.pop();
            min_heap.push(max_top);
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

    } else {
        int min_top = min_heap.top();
        int max_top = max_heap.top();

        if (max_heap.size() < min_heap.size()) {
            if (num >= min_top && num >= max_top) {
                min_heap.pop();
                max_heap.push(min_top);
                min_heap.push(num);
            } else {
                max_heap.push(num);
            }

        } else {
            if (num <= min_top && num <= max_top) {
                max_heap.pop();
                min_heap.push(max_top);
                max_heap.push(num);
            } else {
                min_heap.push(num);
            }
        }
    }


}


void printMedian() {
    if (max_heap.size() > min_heap.size()) {
        printf("%.1f\n", (double) max_heap.top());
    } else if(max_heap.size() < min_heap.size()) {
        printf("%.1f\n", (double )min_heap.top());
    } else {
        double median = max_heap.top() + min_heap.top();
        printf("%.1f\n", median/2.0);
    }
}

int main() {
    int N,X;
    cin >> N;
    while(N--) {
        cin >> X;
        addNumber(X);
        printMedian();
    }

    return 0;
}