#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int arr[n];
		
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		sort(arr,arr+n);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=arr[i]-arr[0];
		}
		cout<<"\n"<<ans<<"\n";
			
	}
}

