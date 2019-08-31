#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> Map;
bool comp(int &a,int &b){
    if(Map[a]!=Map[b]){
        return Map[a]>Map[b];// return true when first is with greater frequency
    }else{
        return a<b;	// return true for smaller element
    }
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int A[n];
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	 
	    for(int i=0;i<n;i++){
	        Map[A[i]]+=1;
	    }
	    sort(A,A+n,comp);
	    for(int i=0;i<n;i++){
	        cout<<A[i]<<" ";
	    }
	    cout<<endl;
	    Map.clear();
	}
	return 0;
}
