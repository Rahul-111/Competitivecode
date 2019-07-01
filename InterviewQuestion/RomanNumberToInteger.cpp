#include<iostream>
using namespace std;
int value(char c){
	if(c=='I')
		return 1;
	if(c=='V')
		return 5;
	if(c=='X')
		return 10;
	if(c=='L')
		return 50;
	if(c=='C')
		return 100;
	if(c=='D')
		return 500;
	if(c=='M')
		return 1000;
	
	return -1;
}
int romanToDecimal(string str){
	int ans=0;
	
	for(int i=0;i<str.length();i++){
		int x=value(str[i]);
		
		if(i+1 < str.length()){
			int y=value(str[i+1]);
			if(x>=y){
				ans=ans+x;
			}
			else{
				ans=ans+y-x;
				i++;
			}
		}
		else{
			ans =ans+x;
		}
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string input;
		cin>>input;
		cout<<romanToDecimal(input);
	}
}
