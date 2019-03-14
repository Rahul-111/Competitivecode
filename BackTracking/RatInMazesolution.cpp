#include<iostream>
using namespace std;
bool RatInMaze(int **arr,int **sol,int n,int x,int y){
	if(x==n-1 && y==n-1){
		sol[x][y]=1;
		return true;
	}
	if(x<0 || y<0 || x>n-1 || y>n-1 || arr[x][y]==0 || sol[x][y]==1)
		return false;
	sol[x][y]=1;
	if(RatInMaze(arr,sol,n,x-1,y)){
		return true;
	}
	if(RatInMaze(arr,sol,n,x+1,y)){
		return true;
	}
	if(RatInMaze(arr,sol,n,x,y-1)){
		return true;
	}
	if(RatInMaze(arr,sol,n,x,y+1)){
		return true;
	}
	sol[x][y]=0;
	return false;
}
int main(){
	int n;
	cin>>n;
	int **arr = new int*[n];
	int **sol = new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
		sol[i]=new int[n];	
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			sol[i][j]=0;
	}
	
	cout<<"your input"<<endl;
	if(RatInMaze(arr,sol,n,0,0))
		cout<<"solution is possible"<<endl;
	else
		cout<<"solution is not possible"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
