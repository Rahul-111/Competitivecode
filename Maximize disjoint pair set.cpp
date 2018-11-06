#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,d;
		cin>>n>>d;
		int a[n];
	    for(int i=0;i<n;i++)
		{
		cin>>a[i];
		}
		long int sum = 0;
	    sort(a,a+n);
	   	for(int i=n-1;i>0;i--)
		{
			if(a[i]-a[i-1]<d)
		   	{
		   		sum+=a[i--]+a[i];
			}
		}
	    cout<<sum<<endl;
	}
	return 0;
}

