#include <iostream>

using namespace std;

const int rows=5;
const int cols=6;

int cost(int i, int j)
{
	//need to now base case, recurive call,
	//how to declare vector, how to intalie the so the first line, and the first chunk of code                                                  
	int weight[rows][cols]={{3,4,1,2,8,6},
							{6,1,8,2,7,4},
							{5,9,3,9,9,5},
							{8,4,1,3,2,6},
							{3,7,2,8,6,4},
						   };
						   
	static int memo[rows][cols]={0};
	
	if(memo[i][j]!=0)
		return memo[i][j];
						   
	if(j==0)
		return weight[i][0];
	
	int left=weight[i][j]+cost(i,j-1);
	
	//doing the up
	int up=weight[i][j]+cost((i+4)%5,j-1);
	
	//doing the down
	int down=weight[i][j]+cost((i+1)%5,j-1);
	
	//getting mins
	int min=left;
	
	if(up<min)
		min=up;
		
	if(down<min)
		min=down;
	//setting memos
	memo[i][j]=min;

	return min;
}

int main()
{
	int ex[rows];
	
	for(int i=0;i<rows;i++)
	{
		ex[i]=cost(i,cols-1);
		cout<<ex[i]<<endl;
	}
	
	int min=ex[0];
	
	for(int a = 1;a<rows;a++)
	{
		if(min>ex[a])
			min=ex[a];
	}
	cout<<"Smallest is "<<min<<endl;
	
	
}
