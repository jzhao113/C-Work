#include <iostream>
#include <cmath>

using namespace std;

int counter=0;

bool test(int x[], int col)
{
	for(int i=0;i<col;i++)
	{
		if(col-i==abs(x[col]-x[i])||x[i]==x[col])
			return false;
	}
	return true;
}

void print(int queenSpots[], int n)
{
	counter++;
	cout<<"Solution #"<<counter<<endl;
		
	for(int a=0;a<n;a++)
		cout<<queenSpots[a]<<" ";
	cout<<endl<<endl;
}

int main()
{
	int n=8;
	int queenSpots[n]={0};
	int c=0,count=0;
	bool flag=false;
	
	while(c!=-1)
	{
		while(c!=n)
		{
			for(int i=queenSpots[c];i<n;i++)
			{
				queenSpots[c]=i;
				if(test(queenSpots,c))
				{
					flag=true;
					break;
				}
			}
			
			if(flag==true)
			{
				flag=false;
				c++;
			}
			else
			{
				queenSpots[c]=0;
				c--;
				if(c==-1)
					break;
				queenSpots[c]++;
			}	
		}
		
		if(c!=-1)
		{
			print(queenSpots,n);
			c--;
			queenSpots[c]++;
		}
	}
}

