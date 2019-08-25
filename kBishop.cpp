#include <iostream>
#include <cmath>
using namespace std;

bool isOk(int x[], int currentPosition, int mod)
{
	for(int i=0;i<currentPosition;i++)
	{
		if(abs( (x[currentPosition]%mod) - (x[i]%mod))==abs((x[currentPosition]/mod) - (x[i]/mod)))
			return false;
			
		if(x[i]>x[currentPosition])
			return false;
	}
	return true;
}

int main()
{
	//towers of haoni for loop
	//shortest path memoization
	
	int n,k;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Enter k:";
	cin>>k;
	
	
	//sets everything besides the first number to -1
	int *bis = new int[k];
	for(int i=0;i<k;i++)
	{
		if(i==0)
			bis[i]=0;
		else
			bis[i]=-1;
	}
	
	int c=1,count=0;
	
	bool flag=false;
	
	while(bis[0]!=-1)
	{
		while(c<k)
		{
			//++bis[c]
			for(int i=bis[c]+1;i<n*n;i++)
			{
				bis[c]=i;
				if(isOk(bis,c,n))
				{
					flag=true;
					break;
				}
			}
			
			if(flag)
			{
				c++;
				flag=false;
			}
			else
			{
				bis[c]=-1;
				break;
			}
			
		}
		
		if(c==k)
		{
			count++;
		}
				
		c--;
	}
	
	cout<<count<<endl;
}
