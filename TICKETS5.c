#include<stdio.h>
#include<string.h>
int main()
{
    int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[101];
    	scanf("%s",a);
        int i,flag=0;
   	    if(strlen(a)<=2)
    	{  
			if(a[0]!=a[1])
          		flag=0;
       		else
          		flag=1;
				  
		}
     	for(i=0;i+2<strlen(a);i++)
        { 
			if(a[i]==a[i+1])
            { 
				flag=1;
              	break;
			}
          	else
            {  
				if(a[i]==a[i+2])
                    continue;
                else
	            { 
					flag =1;
	            } 
            }     
		}
    	if(flag==1)
       		printf("NO\n");
    	else
       		printf("YES\n");
	}
	return 0;
}
