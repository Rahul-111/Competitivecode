#include <bits/stdc++.h>
using namespace std;

int main(){
	const int n=1e5;
	int i,j;
	int arr[n+1];
	for(i=0;i<=n;i++) arr[i]=0;
	for(i=2;i<=n;i++)
	{
	    if(arr[i]==0)
	    {
	        for(j=i;j<=n;j+=i) arr[j]++;
	    }
	}
	int t;
	cin>>t;
	int a,b,k,c,ans,num;
	for(int a0=1;a0<=t;a0++)
	{
	    cin>>a>>b>>k;
	    ans=0;
	    for(i=a;i<=b;i++) if(arr[i]==k) ans++;
	    cout<<ans<<endl;
	}
	return 0;
}

