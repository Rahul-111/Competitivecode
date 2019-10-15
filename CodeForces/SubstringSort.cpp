#include<bits/stdc++.h>
using namespace std;
struct Node{
  string x;
  int m;
};
bool comp(Node &l,Node &r){
	if(l.m<r.m)
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
	Node *p = new Node[n];
	for(int i=0;i<n;i++){
		cin>>p[i].x;
		p[i].m=p[i].x.size();
		
	}
	sort(p,p+n,comp);
// 	for(int i=0;i<n;i++){
// 	    cout<<p[i].x<<" "<<p[i].m<<endl;
// 	}
	int flag=0;
	for(int i=0;i<n-1;i++){
	    string y;
	    y=p[i].x;
	    if(!isPresent(y,p[i+1].x)){
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
	        cout<<p[i].x<<endl;
	    }
	}
// 	sort(s.begin(),s.end(),comp);
// 	for(int i=0;i<n;i++){
// 		cout<<s[i]<<endl;
// 	}
	return 0;
}
