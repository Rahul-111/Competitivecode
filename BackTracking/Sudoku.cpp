#include<bits/stdc++.h>
using namespace std;
int n;
void Display(int** ans) 
{ 
    for (int row = 0; row < n; row++) 
    { 
       for (int col = 0; col < n; col++) 
             cout<<ans[row][col]<<" "; 
        cout<<"\n"; 
    } 
} 
bool UsedInRow(int** arr,int row,int num){
	for(int col=0;col<n;col++)
		if(arr[row][col]==num)
			return true;
	return false;
}
bool UsedInCol(int** arr,int col,int num){
	for(int row=0;row<n;row++){
		if(arr[row][col]==num)
			return true;
	}
	return false;
}
bool UsedInBox(int** arr,int boxStartRow,int boxStartCol,int num){
	for(int row=0;row<3;row++){
		for(int col=0;col<3;col++)
			if(arr[row+boxStartRow][col+boxStartCol]==num)
				return true;
	}
	return false;
}
bool isSafe(int** arr,int row,int col,int num){
	return !UsedInRow(arr,row,num) && !UsedInCol(arr,col,num) 
	&& !UsedInBox(arr,row-row%3,col-col%3,num) &&arr[row][col]==0;
}
bool FindVoidLocation(int** arr,int &row,int &col){
	for(row =0;row<n;row++){
		for(col=0;col<n;col++){
			if(arr[row][col]==0)
				return true;
		}
	}
	return false;
}
bool sudoku(int **arr){
	int row,col;
	
	if(!FindVoidLocation(arr,row,col))
		return true;
	for(int num=1;num<=9;num++){
		if(isSafe(arr,row,col,num)){
			
			arr[row][col]=num;
			
			if(sudoku(arr))
				return true;
			
			arr[row][col]= 0;
		}
	}
	return false;
}
int main()
{
	int** arr;
	cin>>n;
	arr = new int*[n];
	
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	if(sudoku(arr)==true)
		Display(arr);
	else
		cout<<"No Solution exists"<<endl;
	return 0;
}
