
#include<bits/stdc++.h>
using namespace std;
int printMaxPathSum(int** A,int i,int j,int B,int ***dp,int n){
    if(i<0 || j<0 || i>=n || j>=n || B<0)
        return INT_MIN;
    if(B==1 && i==n-1 && j==n-1)
        return A[i][j];
    if(dp[i][j][B-1]!=-1)
        return dp[i][j][B];
    int ans = INT_MIN;
    ans = max(ans,A[i][j]+printMaxPathSum(A,i,j+1,B,dp,n));
    ans = max(ans,A[i][j]+printMaxPathSum(A,i+1,j,B,dp,n));
    ans = max(ans,A[i][j]+printMaxPathSum(A,i-1,j,B-1,dp,n));
    ans = max(ans,A[i][j]+printMaxPathSum(A,i,j-1,B-1,dp,n));
        
	dp[i][j][B]=ans;
	return ans;
}
int main(){
	int n;
	cin>>n;
	int **A;
	A = new int*[n];
	for(int i=0;i<n;i++){
		A[i] = new int[n];
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	}
	int B;
	cin>>B;
	int ***dp;
	dp = new int**[n];
	for(int i=0;i<n;i++){
	    dp[i] = new int*[n];
	    for(int j=0;j<n;j++){
	        dp[i][j] = new int[B];
	    }
	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        for(int k=0;k<=B;k++){
	            dp[i][j][k]=-1;
	        }
	    }
	}
	cout<<printMaxPathSum(A,0,0,B,dp,n);
	return 0;
}
