#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	char arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	//R,l
	string ans="";
	if(n%2==0){
		string L="";
		for(int i=n-2;i>0;i--){
			if(i%2==0)
				L+=arr[i];
		}
		string R="";
		for(int i=1;i<n;i++){
			if(i%2==1){
				R+=arr[i];
			}
		}
		ans+=L;
		ans+=arr[0];
		ans+=R;
		
	}else{//L,R
		string R="",L="";
		for(int i=n-2;i>0;i--){
			if(i%2!=0){
				L+=arr[i];
			}
		}
		for(int i=2;i<n;i++){
			if(i%2==0){
				R+=arr[i];
			}
		}
		ans+=L;
		ans+=arr[0];
		ans+=R;
		
	}
	cout<<ans<<endl;
	return 0;
}
