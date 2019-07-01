#include<bits/stdc++.h>
using namespace std;
int getMinLength(string s,int low,int high){
	if(low>high)
		return 0;
	if(low==high-1){
		if(s[low]==s[high])
			return 0;
		else
			return 1;	
	}
	if(s[low]==s[high])
		return getMinLength(s,low+1,high-1);
	else if(s[low]!=s[high]){
		return 1+min(getMinLength(s,low+1,high),getMinLength(s,low,high-1));
	}
}
//using dynamic programming
int getMinLengthDP(string s,int n){
	int table[n][n],l,h,len;
	
	memset(table,0,sizeof(table));
	for(len=1;len<n;len++){
		for(l=0,h=len;h<n;l++,h++){
			table[l][h] = s[l]==s[h]?
					table[l+1][h-1]:
					1+min(table[l][h-1],table[l+1][h]);
		}
	}
	return table[0][n-1];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string input;
		cin>>input;
		int l,h;
		l=0,h=input.length()-1;
		cout<<getMinLength(input,l,h)<<endl;
		cout<<"By DP = "<<getMinLengthDP(input,input.size());
	}
	return 0;
}
