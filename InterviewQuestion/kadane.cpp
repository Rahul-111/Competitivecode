#include <bits/stdc++.h>
using namespace std;
bool AllPositive(unsigned long long int A[],long long int n){
    for(int i=0;i<n;i++){
        if(A[i]<0)  
            return false;
    }
    return true;
}

bool AllNega(unsigned long long int A[],long long int n){
    for(int i=0;i<n;i++){
        if(A[i]>=0)
            return false;
    }
    return true;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    unsigned long long int A[n];
	    unsigned long long int ans;
	    //taking input
	    for(int i=0;i<n;i++)
	        cin>>A[i];
	    //if all positive
	    if(AllPositive(A,n)){
	        ans=0;
	        for(int i=0;i<n;i++)
	            ans+=A[i];
	    }
	    else if(AllNega(A,n)){
	        ans=A[0];
	        for(int i=1;i<n;i++){
	            ans=max(A[i],ans);
	        }
	    }
	    else{
	        unsigned long long int sum=0;
	        ans=0;
	        
	        for(int i=0;i<n;i++){
	            if(sum<0)
	                sum=0;
	            sum+=A[i];
	            ans=max(sum,ans);
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
