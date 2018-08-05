#include<iostream>
using namespace std;

int main()
{
	int test,n;
	cin>>test;
	while(test--)
	{	
		int count=1,flag;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		flag=a[0];
		
		for(int i=0;i<n-1;i++)
		{	// 8 3 6
			
			if(a[i]>a[i+1] && a[i+1]<flag)
			{
				++count;
				flag=a[i+1];
			}
			
		}
		cout<<count<<"\n";
	}
	return 0;
}
