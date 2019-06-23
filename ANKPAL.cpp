#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/* RAKESH KUMAR*/
int main()
{
	string ipstr;
	cin>>ipstr;
	ll noQue=0;
	cin>>noQue;
	while(noQue--)
	{
		int flag=1,l;
		string ipstr1(ipstr);
		ll arrIndex[4];
		for(int i=0;i<4;i++)
		{
			cin>>arrIndex[i];
		}
		char ch=ipstr1.at(arrIndex[1]-1);
		ipstr1.at(arrIndex[1]-1)=ipstr1.at(arrIndex[0]-1);
		ipstr1.at(arrIndex[0]-1)=ch;
		if(arrIndex[2]<=arrIndex[3] && arrIndex[3]<= ipstr1.length())
		{
			ll len=arrIndex[3]-arrIndex[2]+1;
			string strMain=ipstr1.substr(arrIndex[2]-1,len);
    		for(ll j=strMain.length()-1,i=0;i<strMain.length()/2;++i,--j)
    		{
        		if(strMain[j]!=strMain[i])
            		flag=0;
    		}
		}
		//(flag==1)?cout<<"Yes"<<endl:cout<<"No"<<endl;
		if(flag==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
		ipstr1.clear();		
	}
	return 0;
}
