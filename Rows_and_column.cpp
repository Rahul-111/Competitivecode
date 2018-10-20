#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	
	int row=0,col=0;
	int r[n+1],c[n+1];
	for(int i=1;i<=n;i++)
	{
		r[i]=0;
		c[i]=0;
	}
	string s;
	while(q--)
	{
		cin>>s;
		int y,x;
		cin>>y>>x;
		if(s=="RowAdd")
		{
			r[y]+=x;
		}
		else if(s=="ColAdd")
		{
			c[y] +=x;
		}	
	}
	int maxrow=r[1];
	int maxcol=c[1];
	for(int i=1;i<n;i++)
	{
		if(maxrow < r[i])
			maxrow=r[i];
		if(maxcol < c[i])
			maxcol = c[i];
	}
	cout<<maxrow+maxcol;
	return 0;
}
