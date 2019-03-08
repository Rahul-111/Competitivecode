#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
			
		vector<int > v;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int l,r,c;
			c=i;
			l=(n+c-1)%n;
			r=(n+c+1)%n;
			
			if(a[l]+a[r] < b[c] ){
				if(b[c] > ans) 
					ans=b[c];
			}
		}
		if(ans > 0)
			cout<<ans<<endl;
		else
			cout<<"-1"<<endl;
	}
	return 0;
}
