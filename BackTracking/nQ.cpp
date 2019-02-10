#include<iostream>
#define n 4
using namespace std;
void Display(int A[n][n]){
	static int i=0;
	cout<<++i<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
				cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool isSafe(int A[n][n],int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		if(A[i][col])
			return false;
	}
	for(i=row,j=col; i>=0 && j>=0 ; i--,j--)
		if(A[i][j])
			return false;
	for(i=row,j=col;i>=0 && j<n;i--,j++)
		if(A[i][j])
			return false;
	return true;
}
bool solveNq(int A[n][n],int row){
	
	if(row==n){
		Display(A);
		return true;
	}
	
	for(int i=0;i<n;i++){
		
		bool res = false;
		if(isSafe(A,row,i)){
			
			A[row][i]=1;
			
			//if(solveNq(A,row+1))
			//	return true;
			res = solveNq(A,row+1)||res;
			
			A[row][i]=0;
		}
	}
	return false;
}
int main(){
	cout<<"Solving N queen Problem\n";
	int A[n][n]={0};
	int row=0;
	if(!solveNq(A,row))
		cout<<"Solution not possible\n";
	return 0;
}
