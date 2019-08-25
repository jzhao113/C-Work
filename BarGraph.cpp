#include <iostream>

using namespace std;

int main()
{
	int data[6]={2,2,9,3,4,3};
	
	int greatest=0;
	
	for(int a=0;a<6;a++)
	{
		if(data[a]>greatest)
		{
			greatest=data[a];
		}
	}
	
	for(int a=greatest;a>=1;a--)
	{
		for(int b=0;b<6;b++)
		{
			if(a<=data[b])
			{
				cout<<"X";
			}
			else
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
