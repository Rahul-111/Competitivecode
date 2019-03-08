#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[26]={0};
		string s[n];
		for(int i=0;i<n;i++)
			cin>>s[i];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<s[i].length();j++)
				arr[s[i][j]-97]++;
		}
		
		int count=0;
		for(int i=0;i<26;i++)
			if(arr[i]==n)
				count++;
		cout<<count<<endl;
	}
}
