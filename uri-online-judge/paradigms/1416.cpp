// https://www.urionlinejudge.com.br/judge/pt/problems/view/1416

#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f
#define MAX_N 500

struct team{
    int tries;
    int acc;
    int t_acc;
    
    team(){
        tries = acc = t_acc = 0;
    }
    
    int calc_penalidade(int p) const{
    	return t_acc + tries*p;
	}
    
    bool operator<(const team &vhs) const
    {
        if(acc == vhs.acc) return calc_penalidade(20) < vhs.calc_penalidade(20); // se a quantidade de problemas resolvidos for igual, retorna o menor tempo
        else return acc > vhs.acc; // retorna quem acertou mais
        
    }
    
};


int main()
{
    int N,P,num;
    char str[6];
    
    team v[MAX_N];
    
    while(scanf("%d %d",&N,&P) && N|P)
    {
    	rep(i,0,N) v[i] = team();
        rep(i,0,N)
        {
            rep(j,0,P)
            {
                scanf("%d/%s",&num,str);
                if(str[0] != '-')
                {
                    v[i].tries += num-1;
                    v[i].t_acc += atoi(str);
                    v[i].acc++;
                }
                
            }
            
        }
        sort(v,v+N);
       //ep(i,0,N) printf("%d %d %d\n",v[i].acc,v[i].tries, v[i].t_acc);
		int lo = 1;
		int hi = INF;
		rep(i,1,N)
		{
			if(v[i].acc == v[i-1].acc)
			{
				if(v[i].acc == 0 && v[i-1].acc == 0) break; //ninguem fez pontuação
				
				if(v[i].calc_penalidade(20) == v[i-1].calc_penalidade(20))  //
				{
					lo = hi = 20;
					break;
				}
			
			
				int numerador = v[i-1].t_acc - v[i].t_acc;
				int denominad = v[i].tries - v[i-1].tries;
				int res;
				if(denominad) res = numerador/denominad;
				if(denominad < 0)
				{
					if(numerador%denominad==0) res--;
					if(res > 0 && res < hi) hi=res;
					
				}else if(denominad > 0)
				{
					lo = max(lo, res+1);
				}
			}
		}   
		printf("%d ",lo); 
		hi == INF ? printf("*\n") : printf("%d\n",hi);    
    }
    return 0;
}