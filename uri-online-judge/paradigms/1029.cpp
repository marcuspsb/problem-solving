// https://www.urionlinejudge.com.br/judge/pt/problems/view/1029

#include <bits/stdc++.h>

using namespace std;

int ans;
int fibo(int x)
{	
	ans++;
	if(x == 0) return 0;
	if(x == 1) return 1;
	return fibo(x-1) + fibo(x-2);
}

int main()
{
	int N,k;
	scanf("%d",&N);
	while(N--)
	{
		ans = 0;
		scanf("%d",&k);
		int f = fibo(k);
		printf("fib(%d) = %d calls = %d\n",k,ans-1,f);
	}
	return 0;
}