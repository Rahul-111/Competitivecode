#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int a[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(i>1) //
			{
				if(a[i]!=a[i-1])
				{
					count++;
					continue;
				}
			}
			if(i<n) // 
			{
				if(a[i]!=a[i+1])
				{
					count++;
				}
			}
		}
		cout<<endl;
		cout<<count;
	}
}
