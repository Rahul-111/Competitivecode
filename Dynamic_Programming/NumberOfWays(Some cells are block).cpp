#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,n,p;
	cin>>m>>n>>p;
	int grid[m+1][n+1];
	memset(grid,0,sizeof(grid));
	int i,j;
	while(p--)
	{	
		cin>>i>>j;
		grid[i][j] = -1;
	}
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<grid[i][j]<<"\t";
		}
		cout<<endl;
	}
	// If the initial cell is blocked, there is no way of moving anywhere
	if(grid[1][1] == -1)
	{
		cout<<"0";
		return 0;
	}
	// Initializing the leftmost column
    //Here, If we encounter a blocked cell, there is no way of visiting any cell
    //directly below it.(therefore the break)
    
    for(int i=1;i<=m;i++)
    {
    	if(grid[i][1]==0) grid[i][1]=1;
    	else break;
	}
	//Similarly initialize the topmost row.
	for(int i=2;i<=n;i++)
	{
		if(grid[1][i]==0) grid[1][i]=1;
		else break;
	}
	
	for(int i=2;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(grid[i][j] == -1) continue;

            //While adding the number of ways from the left and top cells,
            //check that they are reachable,i.e. they aren't blocked

            if(grid[i-1][j] > 0) grid[i][j] = grid[i][j] + grid[i-1][j];
            if(grid[i][j-1] > 0) grid[i][j] = grid[i][j] + grid[i][j-1];
		}
	}
	
	//If the final cell is blocked, output 0, otherwise the answer
    //if(grid[m][n] < 0)
    //	cout<<"0";
    //else
    	cout<<grid[m][n];
    return 0;
}

