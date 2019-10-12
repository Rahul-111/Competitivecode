#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	unordered_map<string,string> Map;
	while(m--){
		string x,y;
		cin>>x>>y;
		Map[x]=y;
	}
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	for(int i=0;i<n;i++){
		if( s[i].size() > Map[s[i]].size() ){
			s[i]=Map[s[i]];
		}
	}
	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	return 0;
}
