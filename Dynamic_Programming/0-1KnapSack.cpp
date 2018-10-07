#include<iostream>
using namespace std;
int knapSack(int W,int wt[],int val[],int n)
{
	if(n==0||W==0)
		return 0;
	// If weight of the nth item is more than Knapsack capacity W, then 
   	// this item cannot be included in the optimal solution 
	else if(wt[n-1]>W)
		return knapSack(W,wt,val,n-1);
	// Return the maximum of two cases:  
   	// (1) nth item included  
   	// (2) not included
	else 
		return max(knapSack(W-wt[n-1],wt,val,n-1)+val[n-1],knapSack(W,wt,val,n-1));
}
int KnapSack(int W,int wt[],int val[],int n)
{
	int dp[n+1][W+1];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			if(i==0||w==0)
				dp[i][w]=0;
			else if(wt[i-1]<=W)
				dp[i][w]  = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
			else
				dp[i][w] = dp[i-1][w-1];
		}
	}
	return dp[n][W];
}
int main()
{
	int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout<<"Maximum Profit "<<knapSack(W, wt, val, n); 
    cout<<"\n Using Dynamic Programming";
    cout<<"Maximum Profit "<<KnapSack(W, wt, val, n);
    return 0; 
}
