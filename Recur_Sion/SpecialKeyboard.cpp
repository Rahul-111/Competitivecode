#include<iostream>
using namespace std;
int function(int n,int arr[]){
    if(n<=6)
        return n;
    int max_so_far=0;
    // int max_as=0;
    int multi=2;
    for(int i=n-3;i>=0;i--){
        if(arr[i]==-1){
            arr[i]=function(i,arr); 
        }
        max_so_far=max(max_so_far,multi*arr[i]);
        multi+=1;
    }
    return max_so_far;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=-1;
        if(n>75){
            cout<<"-1"<<endl;
        }else{
            int ans=function(n,arr);
            cout<<ans<<endl;
        }
    }
	return 0;
}
