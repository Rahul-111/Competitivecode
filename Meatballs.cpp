#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long int  n,m;
	while(t--)
	{
		cin>>n>>m;
		
		long long int a[n];
		
		for(int i=0;i<n;i++)
			cin>>a[i];
			
		sort(a,a+n);
		
		int count=0;
		for(int i=n-1;i>=0;i--)
		{
			m=m-a[i];
			count++;
			if(m<=0)
				break;
		}
		if(m>0)
			count =-1;
		cout<<count<<endl;
	}
	return 0;
}
