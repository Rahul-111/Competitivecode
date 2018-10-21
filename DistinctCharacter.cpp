#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		int y;
		int a[26]={0};
		for(int i=0;i<s.length();i++)
		{
			y=s[i]-97;
			a[y] = 1;
		}
		int count=0;
		for(int i=0;i<26;i++)
		{
			if(a[i]==1)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
