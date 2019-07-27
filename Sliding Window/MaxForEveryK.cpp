#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long int n,k;
	    cin>>n>>k;
	    
	    long long int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	        
	    long long int ans=arr[0];
	    for(int i=1;i<k;i++){
	        ans=max(arr[i],ans);
	    }
	    cout<<ans<<" ";
	    for(int i=k;i<n;i++){
	        if(arr[i]>=ans){
	            ans=arr[i];
	            cout<<ans<<" ";
	        }
	        else if(arr[i]<ans && arr[i-k]<ans){
	            cout<<ans<<" ";
	        }
	        else if(arr[i]<ans && arr[i-k]==ans){
	            ans=arr[i-k+1];
	            for(int x=i-k+2;x<=i;x++){
	                ans=max(ans,arr[x]);
	            }
	            cout<<ans<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
