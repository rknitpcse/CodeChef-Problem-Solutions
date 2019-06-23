#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arrSize=0;
	cin>>arrSize;
	int *arr=(int *)malloc(arrSize*sizeof(int));
	for(int i=0;i<arrSize;i++)
		cin>>arr[i];
	int fC=INT_MIN;
	sort(arr,arr+arrSize);
	int begin=arr[0]+arr[1],end=arr[arrSize-2]+arr[arrSize-1];
	for(int v=begin;v<=end;v++)
	{
		int count=0,f=0,l=(arrSize-1);
		while(f<l)
		{
			if(arr[f]+arr[l]==v)
				count++,f++,l--;
			else if(arr[f]+arr[l]<v)
				f++;
			else
				l--;		
		}
		fC=max(fC,count);
	}
	cout<<(2*fC)<<endl;
	free(arr);
	return 0;
}
