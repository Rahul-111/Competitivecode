#include<iostream>

using namespace std;

int main()
{
	long long int N,M;
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{	
		long long int ans=0,q;
		cin>>q;
		int L = max(q-N,N+1);
		int R = min(q-1,2*N);
		if(L>R)
			ans=0;
		else
			ans=R-L + 1;
			
		cout<<ans<<"\n";
	}
	return 0;
}
