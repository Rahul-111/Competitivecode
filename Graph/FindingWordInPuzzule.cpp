#include<iostream>
using namespace std;
bool withinRange(int i,int j,int n,int m){
	if(i<0 || i>n-1||j<0||j>m-1)
		return false;
	return true;
}
//void puzzule(char arr[][7],int i,int j,bool **visited,int n,int m,string s,int &count){
//	if(s[count]==arr[i][j]){
//		count++;
//		visited[i][j]=true;	
//	}
//	if(arr[i][j]=='X' || s[count]!=arr[i][j] || !visited[i+1][j])
//		return ;
//	if(withinRange(i+1,j,n,m))
//	puzzule(arr,i+1,j,visited,n,m,s,count);
//	if(withinRange(i-1,j,n,m))
//	puzzule(arr,i-1,j,visited,n,m,s,count);
//	if(withinRange(i,j+1,n,m))
//	puzzule(arr,i,j+1,visited,n,m,s,count);
//	if(withinRange(i,j-1,n,m))
//	puzzule(arr,i,j-1,visited,n,m,s,count);
//	
//	if(withinRange(i-1,j-1,n,m))
//	puzzule(arr,i-1,j-1,visited,n,m,s,count);
//	if(withinRange(i+1,j-1,n,m))
//	puzzule(arr,i+1,j-1,visited,n,m,s,count);
//	if(withinRange(i-1,j+1,n,m))
//	puzzule(arr,i-1,j+1,visited,n,m,s,count);
//	if(withinRange(i+1,j+1,n,m))
//	puzzule(arr,i+1,j+1,visited,n,m,s,count);
//}
bool findmatch(char arr[][7],string s,int i,int j,int n,int m,int count){
	if(count==s.length())
		return true;
	
	if(i<0 ||j<0 ||i>=n||j>=m)
		return false;
	if(arr[i][j]==s[count]){
		char temp=arr[i][j];
		arr[i][j]='X';
		
		bool res = findmatch(arr, s, i-1,j, n, m, count + 1)|  
                   findmatch(arr, s, i+1,j, n, m, count + 1)|  
                   findmatch(arr, s, i,j-1, n, m, count + 1)|  
                   findmatch(arr, s, i,j+1, n, m, count + 1)|
				   findmatch(arr, s, i-1,j-1,n,m, count + 1)|
				   findmatch(arr, s, i-1,j+1,n,m, count + 1)|
				   findmatch(arr, s, i+1,j+1,n,m, count + 1)|
				   findmatch(arr, s, i+1,j-1,n,m, count + 1);
				   
		arr[i][j]=temp; 
		return res; 
	}
	else
		return false;
}
bool matchWord(char arr[][7],string s,int n,int m){
	bool **visited=new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]=new bool[m];
		for(int j=0;j<m;j++)
			visited[i][j]=false;
	}
	int count,ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==s[0]){
				if(findmatch(arr,s,i,j,n,m,0))
					return true;
			}
		}
	}	
	return false;
}
int main(){
	char arr[3][7]={{'X','C','X','X','X','A','X'},
					{'D','O','N','X','X','N','J'},
					{'X','I','G','N','I','X','X'}};
	string s="CODINGNINJA";
	
	if(matchWord(arr,s,3,7))
		cout<<"word exist"<<endl;
	else
		cout<<"Not found"<<endl;
	return 0;
}
