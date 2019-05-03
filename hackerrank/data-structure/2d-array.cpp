// https://www.hackerrank.com/challenges/2d-array/problem

#include <bits/stdc++.h>

using namespace std;

int MAT[7][7];
int dx[] = {0,0,0,-1,-2,-2,-2};
int dy[] = {0,-1,-2,-1,0,-1,-2};

int getHourglasses(int x, int y){
	int ret = 0;
	for(int i = 0; i < 7; ++i)
		ret += MAT[x+dx[i]][y+dy[i]];
	return ret;
	
}

int main(){

  for(int i = 1; i <= 6; ++i)
    for(int j = 1; j <= 6; ++j)
      cin >> MAT[i][j];

 
  int ans = -9999999;
  for(int i = 3; i <= 6; ++i)
      for(int j = 3; j <= 6; ++j)
  	    ans = max( ans , getHourglasses(i,j));
  cout << ans << endl;
        
  return 0;
}