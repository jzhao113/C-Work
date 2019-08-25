#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//amount of rings in total
	int n;
	cout<<"Put in number"<<endl;
	cin>>n;
	
	//amount of towers available
	vector<int> towers [3]; //talk to lab here to, set it to n, but still worked because I never used the other towers
	
	
	//begins to insert rings into first tower, from highest to lowest
	for(int x=n+1;x>=1;x--)
	{
		towers[0].push_back(x);
	}
	
	//due to alogorithm, you NEED this extra ring in all towers
	towers[1].push_back(n+1);
 	towers[2].push_back(n+1);
 	
 	//initialize variables that identity the tower youre coming from and the tower youre going to, 
	//candidate is smallest available ring that hasnt been moved since the last move, by default, ring 1 will be candidate first
	//move just keeps track of how many total moves were made
	int from=0,to,candidate,move=0;
	
	
	//push_back, pop_back, back, size
	
	//checks if amount of rings available is an even or odd amount, affects the tower we make first move to
	if(n%2==0)
	{
		to=2;
		candidate=1; //talk to lab candidate=2
	}
	else
	{
		to=1;
		candidate=1;
	}
	
	//while tower b has less than the total amount of rings available, print to user what next move will be 
	while(towers[1].size()<n+1)
	{
		cout<<"move number "<<++move<<": Transfer ring " <<candidate<< " from tower "<< char(from+65)<<" to tower "<<char(to+65)<<endl;
		
		towers[to].push_back(towers[from].back());
		towers[from].pop_back();
		
		//the to tower we just moved a ring to CANNOT be the next from tower, so this will test other two available towers for the lowest available
		//number ring
		//this proves why we need that extra ring in all available towers, otherwise it will spit out a runtime error
		//the from tower from the previous turn can be the from tower as many times as possible, but the to tower can only be a to tower once until
		//another tower gets its turn first
		if(towers[(to+1)%3].back() < towers[(to+2)%3].back())
 			from=(to+1)%3;
 		else
 			from=(to+2)%3;
 		
		 //going clockwise for odd num rings, going counterclockwise for even num rings	
 		if(n%2==1)
 		{
 			if(towers[from].back() < towers[(from+1)%3].back())
 				to=(from+1)%3;
			else
				to=(from+2)%3;
		}
		else
		{
			if(towers[from].back() < towers[(from+2)%3].back())
 				to=(from+2)%3;
			else
				to=(from+1)%3;
		}
 			
 		candidate=towers[from].back();
 		//vector commands used: back, pop, size, push_back
	}
}
