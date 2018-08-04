#include<iostream>

using namespace std;

int main()
{
	int test;
	cin>>test;
	int m=test;
	int b[test];
	while(test--)
	{
		int n;
		int ans=0;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int pos;
		cin>>pos;
		
		int value=a[pos-1];
		
		// fint number of element smaller the value
		
		for(int i=0;i<n;i++){
			if(a[i]<value)
				ans++;
		}
		b[test]=ans+1;
	}	
	cout<<"\n";
	for(int i=m-1;i>=0;i--){
		cout<<b[i]<<" ";
	}
	return 0;
}
