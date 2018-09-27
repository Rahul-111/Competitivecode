#include<iostream>
using namespace std;
// Recursive Solution numWays(i,j) = numWays(i-1,j) + numWays(i,j-1)
int numWay(int n,int m)
{	if(n==1 || m== 1)
		return 1;
	int x = numWay(n-1,m) + numWay(n,m-1);
	return x;
}
// Dynamic Programming Approach 
//The base case, as in the previous question, are the topmost row and leftmost column. 
//Here, each cell in topmost row can be visited in only one way, i.e. from the left cell. Similar is the case for the leftmost column. 
int dpNumWay(int n,int m)
{
	int dpWay[n][m];
	dpWay[0][0] =1;
	// initialize first row of NumWays matrix
	for(int i=1;i<n;i++)
		dpWay[i][0] = 1;
	//Initialize first column of NumWays Matrix
	for(int j=1;j<m;j++)
		dpWay[0][j] =1;	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			dpWay[i][j] = dpWay[i-1][j] + dpWay[i][j-1];
		}
	}
	return dpWay[n-1][m-1];
}
int main()
{
	int n,m;
	n=m=3;
	cout<<"Number of ways "<<numWay(n,m)<<endl;
	cout<<"Using Dynamic programming"<<endl;
	cout<<"Number of ways "<<dpNumWay(n,m);
}
