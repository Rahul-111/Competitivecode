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
		int m=s.length();
		int x=0;
		//-+
		for(int i=0;i<m;i++)
		{
			if(i%2==1 && s[i]!='+')
			{
				x++;
			}
			else if(i%2==0 && s[i]!='-')
			{
				x++;
			}
		}
		//+-
		int y=0;
		for(int i=0;i<m;i++)
		{
			if(i%2==1 && s[i]!='-')
			{
				y++;
			}
			else if(i%2==0 && s[i]!='+')
			{
				y++;
			}
		}
		if(x<y)
			cout<<x<<endl;
		else cout<<y<<endl;
	}
	return 0;
}
