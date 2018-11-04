#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string a,b;
	while(t--)
	{
		cin>>a>>b;
		string x=a+b;
		int n;
		cin>>n;
		vector <string > v;
		string c;
		for(int i=0;i<n;i++)
		{
			string m;
			cin>>m;
			c+=m;
		}
		int a[26];
		for(int i=0;i<26;i++)
			a[i]=0;
		for(int i=0;i<x.length();i++)
		{
			a[x[i]-97]++;
		}
		int flag=1;
		for(int i=0;i<c.length();i++)
		{
			a[c[i]-97]--;
			if(a[c[i]-97] < 0)
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
			cout<<"NO"<<endl;
		else	
			cout<<"YES"<<endl;
	}
	return 0;
}
