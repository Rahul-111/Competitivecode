#include<bits/stdc++.h>
using namespace std;
bool withinRange(int i,int j,int n,int m){
	if(i<0||i>n-1||j<0||j>m-1)
		return false;
	return true;
}
void piece(int arr[][5],int i,int j,bool **visited,int n,int m,int &count){
	if(arr[i][j]==1){
		count++;
		visited[i][j]=true;	
	}
	if(arr[i][j]==0)
		return ;
	if(withinRange(i+1,j,n,m)&&!visited[i+1][j])
	piece(arr,i+1,j,visited,n,m,count);
	if(withinRange(i-1,j,n,m)&&!visited[i-1][j])
	piece(arr,i-1,j,visited,n,m,count);
	if(withinRange(i,j+1,n,m)&&!visited[i][j+1])
	piece(arr,i,j+1,visited,n,m,count);
	if(withinRange(i,j-1,n,m)&&!visited[i][j-1])
	piece(arr,i,j-1,visited,n,m,count);
	
}
int largestPiece(int arr[][5],int n,int m){
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
			visited[i][j]=false;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!visited[i][j] &&arr[i][j]==1)
			{
				int count=0;
				piece(arr,i,j,visited,n,m,count);
				ans=max(ans,count);	
			}
		}
	}
	return ans;
}
int main(){
	int arr[4][5]={ {0, 0, 1, 1, 0}, 
                     {1, 0, 1, 1, 0}, 
                     {0, 1, 0, 0, 0}, 
                     {0, 0, 0, 0, 1}}; 
	cout<<"Largest piece = "<<largestPiece(arr,4,5);
	return 0;
}
