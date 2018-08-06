#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t,n,s,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=(int)sqrt(n);
	for(i=s;i>=0;i--)
	{
		if(n%i==0)
		{	printf("%d\n",(n/i)-i);
			break;
		}
	}
	}
	return 0;
}
