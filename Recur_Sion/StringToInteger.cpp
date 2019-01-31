#include<iostream>
#include<cmath>
using namespace std;
int convert(string s){
	if(s.length()==0)
		return 0;
	return s[s.length()-1]-'0' + convert(s.substr(0,s.length()-1))*10; 
}
int main(){
	string s="1234";
	cout<<convert(s)%10<<endl;
	return 0;
}
