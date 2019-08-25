#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> x(3),y(4),z;
	x[0]=0;
	x[1]=5;
	x[2]=6;

	y[0]=1;
	y[1]=2;
	y[2]=6;
	y[3]=7;
	
	int a=0,b=0;
	
	while(a!=x.size()&&b!=y.size())
	{
		if(x[a]<=y[b])
		{
			z.push_back(x[a]);
			a++;
		}
		else
		{
			z.push_back(y[b]);
			b++;
		}
		
		cout<<z.size()<<endl;
	}
	
	cout<<endl;

	if(a<x.size())
	{
		for(int i=a;i<x.size();i++)
		{
			z.push_back(x[i]);
		}
	}
	else if(b!=y.size())
	{
		for(int i=b;i<y.size();i++)
		{
			z.push_back(y[i]);
		}
	}

	for(int i=0;i<z.size();i++)
	{
		cout<<z[i]<<endl;
	}
}
