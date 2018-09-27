#include<iostream>
using namespace std;
int ans=0;

// recursive solution
int maxSum(int arr[][4],int i,int j,int endx,int endy)
{
	if(i==endx-1 && j==endy-1)
		return arr[i][j];
	if( i< endx-1 && j<endy-1 )
	{
		ans = arr[i][j] + max(maxSum(arr,i+1,j,endx,endy) ,maxSum(arr,i,j+1,endx,endy));
	}
	else if(i == endx-1)
	{
		ans = arr[i][j] + maxSum(arr,i,j+1,endx,endy);
	}
	else if(j == endy-1)
	{
		ans = arr[i][j] + maxSum(arr,i+1,j,endx,endy);
	}
	return ans;
}
void display(int a[4][4])
{
	cout<<"Maximun Sum Matrix :\n";
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<a[i][j]<<"  ";	
		}	
		cout<<endl;
	}
}
// dynamic programing soluiton
int dySum(int i,int j,int n ,int m,int a[][4])
{
	int dp[4][4];
	dp[0][0] = a[0][0];
	
	// initialize first row of MaxCost
	for(j=1;j<m;j++)
		dp[0][j] = dp[0][j-1] + a[0][j];
	// initialize first column of MaxCost	
	for(i=i;i<n;i++)
		dp[i][0] = dp[i-1][0] + a[i][0];
	
	//This bottom-up approach ensures that all the sub-problems needed
    // have already been calculated.
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) + a[i][j];
		}
	}
	display(dp);
	return dp[n-1][m-1];
}
int main()
{
	int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	cout<<"  "<<maxSum(arr,0,0,4,4);
	cout<<endl;
	cout<<"Using Dynamic Programming "<<dySum(0,0,4,4,arr);
	return 0;
}
