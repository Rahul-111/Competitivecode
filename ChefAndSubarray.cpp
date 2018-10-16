#include<iostream>
using namespace std;
int main()
{
		int n;
		cin>>n;
		int b[n];
		int a;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			if(a==0)
			{
				flag=0;	
			}
			else
			{
				flag++;
			}
			b[i]=flag;
		}
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(max<b[i])
				max=b[i];
		}
		cout<<endl;
		cout<<max;
	return 0;
}
