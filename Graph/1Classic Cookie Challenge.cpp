#include<bits/stdc++.h>
using namespace std;

#define max 500

//global variable
int n,m;

int adj[max][max];
bool visited[max][max];
vector<int > linesize;

//direction vector that defines which direction to maove
int dR[]={0,0,-1,1};
int dC[]={-1,1,0,0};

//dfs function
void dfs(int r,int c,int &lsize)
{
	visited[r][c]=true;
	
	for(int k=0;k<4;k++)
	{
		int tr = r+dR[k];
		int tc = c+dC[k];
		if(tr >=0 && tr < n && tc >=0 && tc < m && adj[tr][tc] == 1 && !visited[tr][tc])
		{
			lsize++;
			dfs(tr,tc,lsize);
		}
		
	}
}

//funciton to handle the dfs
// for taking input
int main()
{
	cin>>n>>m;
	
	memset(visited,false,sizeof(visited));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>adj[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(adj[i][j]==1 && !visited[i][j])
			{
				int lsize=1;
				dfs(i,j,lsize);
				linesize.push_back(lsize);
			}
		}
	}
	
	cout<<"The total number of lines of choco chips is"<<endl;
	cout<<linesize.size()<<endl;
	cout<<"An the line sizes are as follow -"<<endl;
	
	for(int i=0;i<linesize.size();i++)
		cout<<linesize[i]<<"  ";
	
	return 0;
}
