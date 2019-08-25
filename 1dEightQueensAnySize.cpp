#include <iostream>
#include <cmath>

using namespace std;
bool test(int x[],int col)
{
	for(int a=0;a<col;a++)
	{
		if(col-a==abs(x[col]-x[a])||x[a]==x[col])
		
			return false;
	}
	
	return true;
}

void print(int queenSpots[])
{		
	for(int a=0;a<8;a++)
		cout<<queenSpots[a]<<" ";
	cout<<endl<<endl;
}

int solutions (int n)
{
	int *queenSpots = new int[n];

	//queenSpots={0};
	
	for(int a=0;a<n;a++)
	{
		queenSpots[a]=0;
	}
	
	int c=0, count=0;
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
			count++;
			c--;
			queenSpots[c]++;
		}
	}
	
	delete []queenSpots;
	return count;
}

int main()
{
	int input;
	cout<<"Please enter the amount of Queens ";
	cin>>input;
	for(int a=1;a<=input;a++)
	{
		cout<<"There are "<<solutions(a)<<" solutions for "<<a<<" Queens"<<endl;
	}
}
