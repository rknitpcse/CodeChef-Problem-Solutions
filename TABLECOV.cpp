/*
Problem: Table Covering 
Url: https://www.codechef.com/problems/TABLECOV
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc=0;
	cin>>tc;
	if(tc>=1 && tc<=10)
		while(tc--)
		{
			int N=0,M=0;
			cin>>N>>M;
			int path[N][M];
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
					cin>>path[i][j];
			int req[N+1][M+1];
			int get_top[N+1][M+1];
			memset(req,0,sizeof(req));
			memset(get_top,0,sizeof(get_top));
			for(int i=0;i<N;i++)
				for(int j=(M-1);j>=0;j--)
				{
					req[i][j]=max(get_top[i][j],max(path[i][j],req[i][j+1]-get_top[i][j+1]));
					get_top[i+1][j]=req[i][j]-(req[i][j+1]-get_top[i][j+1]);
				}
			int res=0;
			for (int i=0;i<M;i++)
				res+=get_top[N][i];
			cout<<res<<endl;	
		}
	return 0;
}
