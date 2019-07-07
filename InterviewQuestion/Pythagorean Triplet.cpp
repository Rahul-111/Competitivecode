#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    int flag=0;
	    for(int i=n-1;i>1;i--){
	        int l,r;
	        l=0,r=i-1;
	        while(l<r){
	            if(arr[l]*arr[l]+arr[r]*arr[r]==arr[i]*arr[i]){
	                cout<<"Yes"<<endl;
	                flag=1;
	                break;
	            }
	            else if(arr[l]*arr[l]+arr[r]*arr[r]<arr[i]*arr[i]){
	                l++;
	            }
	            else{
	                r--;
	            }
	        }
	        if(flag==1)
	            break;
	    }
	    if(flag==0)
	        cout<<"No"<<endl;
	}
	return 0;
}
