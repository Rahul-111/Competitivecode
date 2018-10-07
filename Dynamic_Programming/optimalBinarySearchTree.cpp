#include<iostream>
#include<limits>
using namespace std;
int sum(int f[],int i,int j)
{
	int s=0;
	for(int k=i;k<=j;k++)
		s+=f[k];
	return s;
}
int optcost(int freq[],int i,int j)
{
	if(j<i)
		return 0;
	if(j==i)
		return freq[i];
	int fsum=sum(freq,i,j);
	int min =INT_MAX;
	for(int r=i;r<=j;r++)
	{
		int cost=optcost(freq,i,r-1)+optcost(freq,r+1,j);
		if(cost<min)
			min=cost;
	}
	return min+fsum;
}
int optimalSearchTree(int key[],int freq[],int n)
{
	return optcost(freq,0,n-1);
}
int optimalSearchTrees(int keys[],int freq[],int n)
{
	int cost[n][n];
	
	for(int i=0;i<n;i++)
		cost[i][i]=freq[i];
		
	for (int L=2; L<=n; L++) 
    { 
        // i is row number in cost[][] 
        for (int i=0; i<=n-L+1; i++) 
        { 
            // Get column number j from row number i and  
            // chain length L 
            int j = i+L-1; 
            cost[i][j] = INT_MAX; 
  
            // Try making all keys in interval keys[i..j] as root 
            for (int r=i; r<=j; r++) 
            { 
               // c = cost when keys[r] becomes root of this subtree 
               int c = ((r > i)? cost[i][r-1]:0) +  
                       ((r < j)? cost[r+1][j]:0) +  
                       sum(freq, i, j); 
               if (c < cost[i][j]) 
                  cost[i][j] = c; 
            } 
        } 
    } 
    return cost[0][n-1]; 
	
}
int main()
{
	int keys[] = {10, 12, 20}; 
    int freq[] = {34, 8, 50}; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    cout<<"Cost of Optimal BST is "<<optimalSearchTree(keys, freq, n);
    cout<<"\nusing Dynamic Programming";
	cout<<"\nCost of Optimal BST is "<<optimalSearchTrees(keys, freq, n); 
    return 0; 
}
