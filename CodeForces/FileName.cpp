#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	char str[n];
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	int ans=0;
	for(int i=0;i<n-2;i++){
		if(str[i]=='x' && str[i+1]=='x' && str[i+2]=='x'){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
