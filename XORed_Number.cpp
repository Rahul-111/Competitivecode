#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			printf("2\n");
		}
		//if N+1 is power of two
		else if(((n+1)&n)==0)
		{
			printf("%d\n",n/2);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
