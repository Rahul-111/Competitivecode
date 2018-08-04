#include<iostream>

using namespace std;
void sorting(int a[],int n)
{	
	for(int i=1;i<n;i++)
	{	
		int hole=i;
		int value=a[hole];
		while(hole>0 && a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole--;
		}
		a[hole]=value;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{	
		cin>>a[i];
	}
	int c;
	cin>>c;

	int result=a[c-1];
	
	
	cout<<result<<"\n";
	sorting(a,n);
	
	for(int i=0;i<n;i++)
	{
		if(a[i]==result)
		{
			cout<<"\nPostion="<<i+1;
			}		
	}
	return 0;
}