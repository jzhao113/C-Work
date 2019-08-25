#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int rows=5, cols = 6;

void calculateCosts() {
   static int weight[rows][cols] = {{3,4,1,2,8,6},
                                    {6,1,8,2,7,4},
                                    {5,9,3,9,9,5},
                                    {8,4,1,3,2,6},
                                    {3,7,2,8,6,4}};
	
	int cost[rows][cols]={{3,0,0,0,0,0},
						  {6,0,0,0,0,0},
						  {5,0,0,0,0,0},
						  {8,0,0,0,0,0},
						  {3,0,0,0,0,0}};
						  
	for(int colsCost=1;colsCost<6;colsCost++)
	{
		for(int rowsCost=0;rowsCost<5;rowsCost++)
		{
			int left = cost[rowsCost][colsCost-1];
			int up=cost[(rowsCost+4)%5][colsCost-1];
			int down=cost[(rowsCost+1)%5][colsCost-1];
			
			int min=left;
			
			if(up<min)
				min=up;
			if(down<min)
				min=down;
			
			cost[rowsCost][colsCost]=min+weight[rowsCost][colsCost];
			
		}
	}
	
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<6;b++)
		{
			cout<<cost[a][b]<<" ";
			if(cost[a][b]<10)
				cout<<" ";
		}
		
		cout<<endl;
	}
	
	//printing stuff out
	int shortest=cost[0][5];
	int shortestLast=0;
	for(int a=1;a<5;a++)
	{
		if(cost[a][5]<shortest)
		{
			shortest=cost[a][5];
			shortestLast=a;
		}
	}
	
	int path[6]={0,0,0,0,0,shortestLast};
	for(int i=4;i>=0;i--)
	{
		int left = cost[shortestLast][i];
		int up=cost[(shortestLast+4)%5][i];
		int down=cost[(shortestLast+1)%5][i];

		int min2=left;
		if(up<min2)
		{
			min2=up;
			shortestLast = (shortestLast+4)%5;
		}
		if(down<min2)
			shortestLast = (shortestLast+1)%5;
		path[i]=shortestLast;
			
	}
	
	cout<<"Shortest Path: "<<shortest<<endl;
	
	for(int a=0;a<6;a++)
	{
		cout<<path[a];
	}
}

int main() {
   calculateCosts();

}
