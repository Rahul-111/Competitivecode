#include<iostream>
#include<cstring>
using namespace std;
int smatch(string x,string y)
{
	int count=0;
	for(int i=0;i<x.length();i++)
	{
		for(int j=0;j<y.length();j++)
		{
			if(x[i]==y[j])
			{
				y[j]=0;
				count++;
				break;
			}
		}
	}
	return count;
}
int main()
{
	int t;
	cin>>t;
	string x,y;
	while(t--)
	{
		cin>>x>>y;
		int match= smatch(x,y);
		cout<<endl;
		cout<<match<<endl;
	}
}

