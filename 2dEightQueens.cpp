#include <iostream>

using namespace std;

int main()
{
	int b[8][8]={0};
	int r, c=0, count=0;
	b[0][0]=1;
	
	nc: c++;
	if(c==8)
	{
		goto print;
	}
	
	r=-1;
	nr:r++;
	if(r==8)
		goto backTrack;
	for(int i=0;i<c;i++)
	{
		if(b[r][i]==1)
			goto nr;
	}
	for(int i=1;r-i>=0&&c-i>=0;i++)
	{
		if(b[r-i][c-i]==1)
			goto nr;
	}
	for(int i=1;r+i<8&&c-i>=0;i++)
	{
		if(b[r+i][c-i]==1)
			goto nr;
	}
	b[r][c]=1;
	goto nc;
	
	backTrack:
	c--;
	if(c==-1)
		return 0;
	r=0;
	while(b[r][c]!=1)
		r++;	
	b[r][c]=0;
	goto nr;
	
	print:
	count++;
	cout<<count<<endl;
	for(int a=0;a<8;a++)
	{
		for(int i=0;i<8;i++)
		{
			if(i==0)
				cout<<b[a][i];
			else
				cout<<","<<b[a][i];
		}
		cout<<endl;
	}
	cout<<endl;
	goto backTrack;
}
