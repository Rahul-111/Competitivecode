#include<iostream>
using namespace std;
bool isVowel(char c){
	if(c=='A'||c=='E'||c=='Y'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
		return true;
	return false;
}
bool isUpper(char c){
	if(c>='A' && c<='Z')
		return true;
	return false;
}
int main(){
	string s;
	cin>>s;
	string ans="";
	for(int i=0;i<s.size();i++){
		if(isVowel(s[i]))
			continue;
		else if(!isVowel(s[i])){
			ans+=".";
			if(isUpper(s[i])){
				s[i]=s[i]+32;
			}
			ans+=s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
