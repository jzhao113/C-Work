#include <iostream>

using namespace std;

bool tester(int q[], int c)
{
				// W0 W1 W2
	int mp[3][3]={{0,2,1}, //M0
		   		  {0,2,1}, //M1
		   		  {1,2,0}};//M2
		 
		 		// M0 M1 M2  		  
	int wp[3][3]={{2,1,0}, //W0
		   		  {0,1,2}, //W1
		   		  {2,0,1}};//W2
	
	for(int i=0;i<c;i++)
	{
		//if the woman is already married 
		if(q[c]==q[i])
			return false;
		//if any other men before this like this new woman
		if(mp[i][q[c]]<mp[i][q[i]]   &&   wp[q[c]][i]<wp[q[c]][c])
			return false;
		//if this man likes any other women before this current woman
		if(mp[c][q[i]]<mp[c][q[c]]	&&	wp[q[i]][c]<wp[q[i]][i])
			return false;
	}
	
	return true;
}

void printer(int q[])
{
	cout<<"Man	Woman"<<endl;
	for(int i=0;i<3;i++)
	{
		cout<<i<<"	"<<q[i]<<endl;
	}
	cout<<endl;
}

void finder(int q[], int c)
{
	if(c==3)
	{
		printer(q);
		return;
	}
	else
	{
		for(int a=++q[c];a<3;a++)
		{
			q[c]=a;
			if(tester(q,c))
			{
				c++;
				finder(q,c);
			}
		}
		
		q[c]=-1;
		c--;
		if(c==-1)
			exit(0);
		finder(q,c);
	}
	
}

int main()
{
	int q[3]={0,-1,-1};
	finder(q,1);
}
