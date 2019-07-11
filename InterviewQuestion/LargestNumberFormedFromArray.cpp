#include<bits/stdc++.h>
using namespace std;
int comp(string x,string y){
    string xy=x.append(y);
    string yx=y.append(x);
    
    return xy.compare(yx)>0?1:0;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i=0;i<n;i++)
	        cin>>s[i];
	    sort(s,s+n,comp);
	    for(int i=0;i<n;i++)
	        cout<<s[i];
	   cout<<endl;
	}
	return 0;
}
