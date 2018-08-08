#include<iostream>
using namespace std;
int a[40]={0};

int recursion(int n)
{
	if(n<=2)
		return a[n]=n;
	if(n==3)
	    return a[n]=4;
	//if(a[n])
	//	return a[n];
	return a[n]=recursion(n-1)+recursion(n-2)+recursion(n-3);
}
int main()
{
	int n;
	cout<<"Enter a number:";
	cin>>n;
	cout<<recursion(n);
	return 0;
}
