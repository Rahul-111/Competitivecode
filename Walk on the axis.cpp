#include<iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		long long int  N, ans;
		cin>>N;
		if(N==0)
			cout<<N+1;
		else
			{
			ans = N*(N+3)/2;
			cout<<ans ; 
		}
	}
}
