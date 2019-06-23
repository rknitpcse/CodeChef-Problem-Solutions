#include<bits/stdc++.h>
#define MAX 2001
using namespace std;
typedef long long ll;
int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll num=0;
        cin>>num;
        ll r[MAX],p[MAX],pos=0,x;
        memset(r,0,MAX*sizeof(r[0]));
        ll count=0,temp;
        for(ll i=0;i<num;i++)
        {
            cin>>x;
            if(r[x+1000]==0)
               p[pos++]=x;
            r[x+1000]++;
        }
        for(ll i=0;i<pos;i++)
        {
            temp=r[p[i]+1000];
            temp=temp*(temp-1)/2;
            count+=temp;
            for(ll j=i+1;j<pos;j++)
            {
                if(abs((p[i]+p[j]))%2==0)
                {
                  if(r[(p[i]+p[j])/2+1000]!=0)
                  	count+=r[p[i]+1000]*r[p[j]+1000];
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
