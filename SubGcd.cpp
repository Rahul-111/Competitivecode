#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	int i;
	i=min(a,b);
	if(i==0)
		return max(a,b);
	else
	{
		for(i=min(a,b);i>=1;i--)
		{
			if(a%i==0 && b%i==0)
				break;
		}
	}
	return i;
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			ans=gcd(a,ans);
		}
		cout<<endl;
		if(ans==1)
			cout<<n;
		else cout<<"-1";
	}
	return 0;
	cout<<gcd(9,10);
}
