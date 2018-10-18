#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i,j;
	while(n--)
	{
		int count =0;
		cin>>i>>j;
		while(i!=j)
		{
			if(i>j)
			{
				i=i/2;
				count++;
			}
			if(j>i)
			{
				j=j/2;
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
