#include<bits/stdc++.h>
using namespace std;
bool comp(string &l,string &r){
	if(l.size()<r.size())
		return true;
	return false;
}
bool isPresent(string y,string x){
    if(y==x)
        return true;
    for(int i=0;i<=x.size()-y.size();i++){
        int k;
        for(k=0;k<y.size();k++){
            if(y[k]!=x[i+k])
                break;
        }
        if(k==y.size())
            return true;
    }
    return false;
}
int main(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	sort(s,s+n,comp);
//	for(int i=0;i<n;i++)
//		cout<<s[i]<<endl;
	
	int flag=0;
	for(int i=0;i<n-1;i++){
	    if(!isPresent(s[i],s[i+1])){
	        flag=1;
	        break;
	    }
	}
	if(flag==1){
	    cout<<"NO"<<endl;
	}
	else{
	    cout<<"YES"<<endl;
	    for(int i=0;i<n;i++){
	        cout<<s[i]<<endl;
	    }
	}
	return 0;
}
