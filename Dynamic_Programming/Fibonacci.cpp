#include<iostream>
using namespace std;
int fiB[100];
int fibonacci(int n)
{
	if(n<=1)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}
int fib(int n)
{
	if(fiB[n] == -1)
	{
		if(n<=1)
			fiB[n]=n;
		else
			fiB[n]=fib(n-1)+fib(n-2);
	}
	return fiB[n];
}
int fibDy(int n)
{
	int F[n+2];
	F[0]=0;
	F[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		F[i] = F[i-1]+F[i-2];
	}
	return F[n];
}
int main()
{
	for(int i=0;i<100;i++)
		fiB[i]=-1;	
	int  n=41;
	cout<<"  "<<fibonacci(n);
	cout<<"\n  "<<fib(n);
	cout<<"\n  "<<fibDy(n);
	return 0;
}
