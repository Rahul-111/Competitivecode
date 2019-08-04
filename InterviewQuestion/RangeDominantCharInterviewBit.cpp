#include<iostream>
using namespace std;
void preproc(string s,int **p){
	int n=s.size();
	
	for(int i=0;i<n;i++){
		
		p[i][s[i]-'a']++;
		
		if(i){
			for(int j=0;j<26;j++){
				p[i][j]+=p[i-1][j];
			}
		}
	}
}
int countMaxDominating(int **p,int l,int r){
	
	int arr[26]={0};
	for(int i=0;i<26;i++){
		
		if(l>0)
			arr[i]=p[r][i]-p[l-1][i];
		else
			arr[i]=p[r][i];
	}
	
	int maxfreq=0;
	for(int i=0;i<26;i++){
		maxfreq=max(maxfreq,arr[i]);
	}
	
	int count=0;
	for(int i=0;i<26;i++){
		if(arr[i]==maxfreq)
			count++;
	}
	
	return count;
}
int main(){
	string s;
	cin>>s;
	
	int no_of_q;
	cin>>no_of_q;
	
	int **p = new int*[s.size()];
	for(int i=0;i<s.size();i++){
		p[i] = new int[26];
	}
	
	for(int i=0;i<s.size();i++){
		for(int j=0;j<26;j++){
			p[i][j]=0;
		}
	}
	
	preproc(s,p);
	while(no_of_q--){
		int l,r;
		cin>>l>>r;
		
		int x = countMaxDominating(p,--l,--r);
		cout<<x<<endl;
	}
}
