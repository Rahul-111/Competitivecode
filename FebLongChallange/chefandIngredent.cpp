#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string *dish = new string[1000];
		int n;
		cin>>n;
		
		int arr[26]={0};
		for(int i=0;i<n;i++){
			cin>>dish[i];
		}
		set<char > S;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<dish[i].length();j++){
				S.insert(dish[i][j]);
			}
			
			//mapping unit char in string
			for(set<char >::iterator it=S.begin();it!=S.end();it++)
				arr[*it-'a']++;
				
			//reset set S to empty
			set<char >::iterator start,end;
			start=S.begin();
			end = S.end();
			S.erase(start,end);
			
		}
		int count=0;
		for(int i=0;i<25;i++){
			if(arr[i]==n)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
