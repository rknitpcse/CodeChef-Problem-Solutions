#include<bits/stdc++.h>
#define SIZE 500010
#define MAX 222
#define M 201
using namespace std;
const int MOD=1e9+7;
int succesor[SIZE],rot[SIZE],too[SIZE],n,x,y,p2[SIZE],C[MAX][MAX],nedge,siz[SIZE],tmp[SIZE],ts,t;
long long f[M][M][M],P[MAX],g[M][M][M],F[MAX];
void update(int x,int y)
{
	succesor[++nedge]=rot[x];
	rot[x]=nedge;
	too[nedge]=y;
}
void dfsTraversal(int x,int l)
{
	siz[x]=1;
	for(int i=rot[x];i;i=succesor[i])
	{
		int y=too[i];
		if (y==l) continue;
		dfsTraversal(y,x);
		siz[x]+=siz[y];
	}
	ts=0;
	for (int i=rot[x];i;i=succesor[i])
	{
		int y=too[i];
		if (y==l) continue;
		tmp[++ts]=y;
	}
	t=0;
	for(int i=0;i<=ts;++i)
	{
		t+=siz[tmp[i]];
		for(int j=0;j<=t;++j)
			for(int k=0;k<=t;++k)
				g[i][j][k]=0;
	}
	g[0][0][0]=1;
	t=0;
	for(int i=0;i<=ts-1;++i)
	{
		t+=siz[tmp[i]];
		for(int j=0;j<=t;++j)
			for(int k=0;k<=t;++k)
				if (g[i][j][k])
				{
					for(int J=0;J<=siz[tmp[i+1]];++J)
						for(int K=0;K<=siz[tmp[i+1]];++K)
							(g[i+1][j+J][k+K]+=g[i][j][k]*f[tmp[i+1]][J][K])%=MOD;
				}
	}
	t+=siz[tmp[ts]];
	for(int j=0;j<=t;++j)
		for(int k=0;k<=t;++k)
		{
			(f[x][j][k+1]+=g[ts][j][k])%=MOD;
			(f[x][j+1][0]+=g[ts][j][k]*P[k+1])%=MOD;
		}
}
void getinput(int &v)
{
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') 
		fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) 
		v=v*10+ch-'0';
    if(fu) 
		v=-v;
}
int main()
{
	cin>>n;
	p2[0]=1;
	for(int i=1;i<=4000;++i) 
		p2[i]=p2[i-1]*2%MOD;
	for(int i=1;i<=n;++i) 
		P[i]=p2[(i-2)*(i-1)/2];
	C[0][0]=1;
	for(int i=1;i<=200;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j) 
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	}
	for(int i=2;i<=n;++i)
	{
		getinput(x),getinput(y);
		update(x,y),update(y,x);
	}
	dfsTraversal(1,0);
	for(int i=1;i<=n;++i) F[i-1]=f[1][i][0];
	for(int i=n-1;i>=0;--i)
		for(int j=i+1;j<=n-1;++j)
			(F[i]-=F[j]*C[j][i])%=MOD;
	for(int i=1;i<=n;i++) 
		cout<<((F[i-1]%MOD+MOD)%MOD)<<" ";
	cout<<endl;	
	return 0;
}
