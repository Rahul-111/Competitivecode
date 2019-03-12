#include<iostream>
using namespace std;
bool isSafe(int board[][10],int i,int j,int n){
	//check col
	for(int row=0;row<i;row++){
		if(board[row][j]==1)
			return false;
	}
	//check for left diagonal
	int x=i;
	int y=j;
	while(x>=0 && y>=0){
		if(board[x][y]==1)
			return false;
	x--;
	y--;
	}
	//check for right diagonal
	x=i;
	y=j;
	while(x>=0 && y<n){
		if(board[x][y]==1)
			return false;
	x--;
	y++;
	}
	return true;
}
bool solveNQ(int board[][10],int i,int n){
	if(i==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(board[i][j]==1){
					cout<<"Q ";
				}
				else{
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		
		cout<<endl;//return true first solution
		return false;// to print all the solution
	}
	for(int j=0;j<n;j++){
		if(isSafe(board,i,j,n)){
			board[i][j]=1;
			bool nextQueen=solveNQ(board,i+1,n);
			if(nextQueen){
				return true;
			}
			//if assumption is wrong the backtrack 
			board[i][j]=0;
		}
	}
	//have tried for all position in the current row but couldn't place a queen
	return false;
}
int main(){
	int n;
	cin>>n;
	int board[10][10]={0};
	solveNQ(board,0,n);
	return 0;
}
