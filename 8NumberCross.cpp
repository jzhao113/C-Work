#include <iostream>
#include <cmath>

using namespace std;

int globalCounter=0;

bool test(int boxes[],int boxNumber)
{
	
	/*
	int neighbors[8][5]={{-1},//-1
						{0,-1},//0,-1
						{0,1,-1},//0,-1
						{0,2,-1},//0,1,2,-1
						{1,2,-1},//0,1,3,-1
						{1,2,3,4,-1},//1,4,-1
						{2,3,5,-1},//2,3,4,-1
						{4,5,6,-1}};//3,4,5,6,-1
	*/
	
	int neighbors[8][5]={{-1},
						 {0,-1},
						 {1,-1},
						 {0,1,2,-1},
						 {1,2,3,-1},
						 {2,4,-1},
						 {0,3,4,-1},
						 {3,4,5,6,-1}};
	
	int count=0;
	
	while(neighbors[boxNumber][count]!=-1)
	{
		
		if(abs(boxes[neighbors[boxNumber][count]]-boxes[boxNumber])==1)
			return false;
		
		++count;
	}
	
	for(int a=0;a<boxNumber;a++)
	{
		if(boxes[a]==boxes[boxNumber])
			return false;
	}
	
		
	return true;
	
	
}

void print(int boxes[])
{
	globalCounter++;
	cout<<"Solution #"<<globalCounter<<endl;
	/*
	PRINTING ANOTHER TEST SET
	cout<<" "<<boxes[1]<<boxes[4]<<endl;
	cout<<boxes[0]<<boxes[2]<<boxes[5]<<boxes[7]<<endl;
	cout<<" "<<boxes[3]<<boxes[6]<<endl<<endl;
	*/
	
	
	cout<<" "<<boxes[1]<<boxes[2]<<endl;
	cout<<boxes[0]<<boxes[3]<<boxes[4]<<boxes[5]<<endl;
	cout<<" "<<boxes[6]<<boxes[7]<<endl<<endl;
	
	for(int a=0;a<8;a++)
	{
		cout<<boxes[a];
	}
	cout<<endl;
}

void solutions(int boxes[], int boxNumber)
{
	if(boxNumber==8)
	{
		print(boxes);
		solutions(boxes,7);
	}	
	else
	{
		for(int a=++boxes[boxNumber];a<=8;a++)
		{
			boxes[boxNumber]=a;
			
			if(test(boxes,boxNumber))
				solutions(boxes,++boxNumber);
		}
		
		boxes[boxNumber]=0;
		boxNumber--;
		
		if(boxNumber==-1)
			exit(0);
			
		//boxes[boxNumber]++;
		solutions(boxes,boxNumber);
	}
}

int main()
{
	int boxes[8]={0};
	int boxNumber=0;
	solutions(boxes,boxNumber);
}
