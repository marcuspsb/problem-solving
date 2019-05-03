// https://www.urionlinejudge.com.br/judge/pt/problems/view/1474
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ll;

const int SZ = 2 ;
const int mod = 1000000;

typedef pair<ll, ll> ii;
ll k , l , n ; 

struct Matriz{
    ll mat[SZ][SZ];
};
Matriz matMul(Matriz A,Matriz B)
{
    Matriz C;
    for(int i = 0 ; i < SZ ; i++)
        for(int j = 0 ;j < SZ ;j++)
        {
            C.mat[i][j] = 0 ;
            for(int k = 0 ; k < SZ ;k++){
               C.mat[i][j]= (C.mat[i][j]%mod + ((A.mat[i][k]%mod)*(B.mat[k][j]%mod)%mod	));
            }
        }
    return C;
}

Matriz matExpo(Matriz BASE,ll p) 
{
    if(p == 1 )return BASE;
    Matriz R = matExpo(BASE, p/2 );
    R = matMul(R,R);
    if(p%2 == 1) R = matMul(R,BASE);
    return R;
}

int main()
{
    Matriz Base ;
    
  
    while(scanf("%llu%llu%llu",&n,&k,&l) != EOF)
    {
       n /= 5;
       if(n == 0)
       { 
         	 printf("000001\n");
      	 	 continue;
       }
       Base.mat[0][0] = 0;
       Base.mat[0][1] = l;
       Base.mat[1][0] = 1;
       Base.mat[1][1] = k;
	   
       Matriz resp = matExpo(Base,n);
       
       printf("%06llu\n",resp.mat[1][1]%mod);
       
    }
}