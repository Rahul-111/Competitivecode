#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x,ans;
		cin>>n>>k;
		set<int > s,w;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			s.insert(x);
		}
		ans = k;
		w.insert(k);
		set <int > :: iterator i;
		set <int > :: iterator j;  
		for(i=(s).begin();i!=(s).end();i++)
		{
			for(j=w.begin();j!=w.end();j++)
			{
				int y=*i^*j;
				ans=max(ans,y);
				w.insert(y);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
