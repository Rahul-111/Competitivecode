#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		unsigned long long int n;
		cin>>n;
		unsigned long long int A[n],S=0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			A[i]-=1;
		}
		for(int i=0;i<n;i++){
			S+=A[i];
		}
		cout<<S+1<<endl;
	}
	return 0;
}
