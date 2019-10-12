#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	char str[n];
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	
	unordered_map<string,int> Map;
	for(int i=0;i<n-1;i++){
		string x="";
		x+=str[i];
		x+=str[i+1];
		Map[x]+=1;
	}
	int fre=0;
	string ans;
	for(unordered_map<string,int>::iterator it=Map.begin();it!=Map.end();it++){
		if(it->second > fre){
			ans=it->first;
			fre=it->second;
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
