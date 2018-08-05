#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int test,n,m;
	string a,b;
	cin>>test;
	while(test--)
	{
		char c;
		int match=0;
		cin>>a>>b;
		n=a.length();//Jewel
		m=b.length();//Stone
		
		for(int i=0;i<m;i++)
		{
			c=b[i];
			for(int j=0;j<n;j++)
			{
				if(c==a[j])
				{
					match++;
					break;	
				}
			}
		}
		cout<<"\n"<<match;
	}
}
