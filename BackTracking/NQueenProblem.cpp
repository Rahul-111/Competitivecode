#include<iostream>
#define N 4
using namespace std;
void display(int board[N][N])
{
	int i,j;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<board[i][j]<<"  ";
		}
		cout<<"\n";
	}
}
bool isSafePos(int board[N][N],int row,int col)
{
	int r,c;
	
	for(c=0;c<col;c++)
	{
		if(board[row][c]==1){
			return false;
		}
	}
	for(r=row,c=col;c>=0 && r>=0;r--,c--)
	{
		if(board[r][c]==1){
			return false;
		}
	}
	
	for(r=row,c=col;c>=0 && r<N;r++,c--)
	{
		if(board[r][c]==1){
			return false;
		}
	}
	
	return true;
}

bool solveNQ(int board[N][N],int col)
{
	int i;
	if(col>=N)
	{
		return true;
	}
		for(int i=0;i<N;i++)
		{
			if(isSafePos(board,i,col)==true)
			{
				board[i][col]=1;
				
				if(solveNQ(board,col+1)==true){
					return true;
				}
				board[i][col]=0;
			}
		}
	return false;
}
int main()
{
	int board[N][N] = {};
	if(solveNQ(board,0)==false){
		cout<<"No Solution\n";
	}
	else{
		display(board);
	}
	return 0;
}
