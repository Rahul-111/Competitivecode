#include<iostream>
#include<algorithm>
#define M 100000007
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a[3];
		for(int i=0;i<3;i++)
		{
			cin>>a[i];
		}
		sort(a,a+3);
		int ans = a[0]*(a[1]-1)%M*(a[2]-2)%M;
		ans = ans%M;
		cout<<ans<<endl;
	}
}
