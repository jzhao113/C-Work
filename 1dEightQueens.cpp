#include <iostream>
#include <cmath>

using namespace std;

int counter=0;

bool test(int x[],int col)
{
	for(int a=0;a<col;a++)
	{
		if(col-a==abs(x[col]-x[a])||x[a]==x[col])
		
			return false;
	}
	
	return true;
}

void print(int q[])
{
	typedef char box[5][7];
	
	box bb,wb,*board[8][8];
	
	box wq={{' ',' ',' ',' ',' ',' ',' '},
		   {' ',char(219),' ',char(219),' ',char(219),' '},
		   {' ',char(219),char(219),char(219),char(219),char(219),' '},
		   {' ',char(219),char(219),char(219),char(219),char(219),' '},
		   {' ',' ',' ',' ',' ',' ',' '}};
	
		
	box bq={{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
			{char(219),' ',char(219),' ',char(219),' ',char(219)},
			{char(219),' ',' ',' ',' ',' ',char(219)},
			{char(219),' ',' ',' ',' ',' ',char(219)},
			{char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++)
		{
			wb[i][j]=' ';
			bb[i][j]=char(219);
		}
	}
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if((i+j)%2==0)
				board[i][j]=&wb;
			else
				board[i][j]=&bb;
		}
	}
	
	for(int i=0;i<8;i++)
	{
		if((i+q[i])%2==0)
		{
			board[q[i]][i]=&wq;
		}
		else
		{
			board[q[i]][i]=&bq;
		}
	}
	
	cout<<++counter<<endl;
	
	cout<<"  ";
	for(int i=0;i<7*8;i++)
	{
		cout<<'_';
	}
	cout<<endl;
	
	for(int i=0;i<8;i++)
	{
		for(int k=0;k<5;k++)
		{
			cout<<char(179);
			for(int j=0;j<8;j++)
			{
				for(int l=0;l<7;l++)
				{
					cout<<(*board[i][j])[k][l];
				}
				
			}
			cout<<char(179)<<endl;
		}
	}
	
	cout<<"  ";
	for(int i=0;i<7*8;i++)
	{
		cout<<char(196);
	}
	cout<<endl<<endl<<endl;
}

void solutions (int queenSpots[],int col)
{
	if(col==8) 
	{
		print(queenSpots);
		return;
	}
	else
	{
		for(int i=queenSpots[col];i<8;i++)
		{
			queenSpots[col]=i;
			if(test(queenSpots,col))
			{
				solutions(queenSpots,++col);
			}
		}
		
		queenSpots[col]=0;
		col--;
		if(col==-1)
			exit(0);
		queenSpots[col]++;
		solutions(queenSpots,col);
	}
	
}

int main()
{
	int queenSpots[8]={0};
	solutions(queenSpots,1);
}
