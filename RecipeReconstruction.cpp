#include<iostream>
#include<cmath>
#define MOD 10000009
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n;
	while(t--)
	{
		string s;
		cin>>s;
		n=s.length();
		int i=0;
		int j=n-1;
		int res=1;
		while(i<=j)
		{
			if(s[i]=='?' && s[j]=='?')
			{
				res=(res*26)%MOD;
			}
			if(s[i]!='?' && s[j]!='?' && s[i]!=s[j])
			{
				res=0;
				break;
			}
			i++;j--;
		}
		cout<<res<<endl;
	}
}
