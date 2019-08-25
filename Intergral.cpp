#include <iostream>

using namespace std;

typedef double (*FUNC)(double b);

double line(double x)
{
	return x;
}

double square(double x)
{
	return x*x;
}

double cube(double x)
{
	return x*x*x;
}

double integrate(FUNC f, double a, double b)
{
	double sum=0,x=a+.0001/2;
	while(x<=b)
	{
		sum+=f(x)*0.0001;
		x+=0.0001;
	}
	
	return sum;
}

int main()
{
	cout<<integrate(line,1,5)<<endl;
	cout<<integrate(square,1,5)<<endl;
	cout<<integrate(cube,1,5);
	

}
