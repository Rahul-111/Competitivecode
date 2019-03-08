#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int arr[26]={0};
		for(int i=0;i<s.length();i++)
			arr[s[i]-'A']++;
		long long int max=0;
		for(int i=0;i<26;i++)
		{
			if(max < arr[i])
				max=arr[i];
		}
		cout<<s.length()-max<<endl;
	}
	return 0;
}
