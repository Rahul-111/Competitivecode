#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	string t1;
	getline(cin,t1);
	while(t--){
		string s;
		getline(cin,s);    
		string ans="";
		unordered_set<char> hash;
		for(int i=0;i<s.length();i++){
			if(hash.find(s[i])==hash.end()){
				ans+=s[i];
				hash.insert(s[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
