#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    priority_queue<int,vector<int>,greater<int>> pq;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<k-1;i++){
	        pq.push(arr[i]);
	        cout<<"-1"<<" ";
	    }
	    pq.push(arr[k-1]);
	    for(int i=k;i<n;i++){
	        if(arr[i]>pq.top()){
	            cout<<pq.top()<<" ";
	            pq.pop();
	            pq.push(arr[i]);
	        }
	        else{
	            cout<<pq.top()<<" ";
	            
	        }
	    }
	    cout<<pq.top()<<endl;
	}
	return 0;
}
