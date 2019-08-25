#include <iostream>

using namespace std;

//Function to turn base 10 to base 2
int binary(int a)
{
	if(a==0)
	{
		return 0;
	}
	
	return binary(a/2)*10+a%2;
}

int main()
{
		//Asking for needed infomation
		int expo, dights=0,num,x=1,mod;
		cout<<"Enter the base number: ";
		cin>>num;
		cout<<"Enter the exponent: ";
		cin>>expo;
		cout<<"Enter the mod number: ";
		cin>> mod;
	
		//Turning exponent into binary by calling function 'binary' and making a copy of the binary result 
		expo=binary(expo);
		int copy=expo;
	
		//Using copy to get the amount of dights of the binary number 
		while(copy>0)
		{
			copy=copy/10;
			dights++;
		}
		
		//The loop to find the answer 
		for(int a=1;a<=dights;a++)
		{
			if(expo%10==1)
			{
				x=(x*num)%mod;
				num=(num*num)%mod;
			}
			else
			{
				num=(num*num)%mod;
			}		
			expo=expo/10;			
		}
	
		//Printing final answer
		cout<<"The answer is: "<<x<<endl<<endl;
		
	//}
	
	return 0;
		
}
