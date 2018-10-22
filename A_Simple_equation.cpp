#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,A,B,C;
		cin>>N>>A>>B>>C;
		int sol=0;
		for(int i=0;i<=A;i++)
		{
			for(int j=0;j<=B;j++)
			{
				int c = N-i-j;
				if(c >=0)
				{
					if(c <= C)
						sol+=c+1;	// as zero is include
					if(c > C)
						sol+=C+1;	
				}
			}
		}
		cout<<endl;
		cout<<sol;
	}
}
