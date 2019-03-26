#include<iostream>
#include<climits>
using namespace std;
int findMinVertex(int* weights,bool* visited,int n){
	int minVertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] &&(minVertex==-1 ||weights[i] < weights[minVertex])){
			minVertex=i;
		}
	}
	return minVertex;
}
void prims(int **adjmatrix,int n){
	
	bool *visited = new bool[n];
	int* weights = new int[n];
	int* parent = new int[n];
	int indexOfmini=INT_MAX;
	
	
	for(int i=0;i<n;i++){
		visited[i]=false;
		weights[i]=INT_MAX;
	}
	parent[0]=-1;
	weights[0]=0;
	
	for(int i=0;i<n-1;i++){
		int minVertex = findMinVertex(weights,visited,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++){
			if(adjmatrix[minVertex][j]!=0 && !visited[j]){
				if(adjmatrix[minVertex][j] < weights[j]){
					weights[j]=adjmatrix[minVertex][j];
					parent[j]=minVertex;
				}
			}
		}
	}
	//Time complexity is O(n^2)
	for(int i=1;i<n;i++){
		if(parent[i] < i){
			cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
		}else{
			cout<<i<<" "<<parent[i]<<" "<<weights[i]<<endl;
		}
	}
	
}
int main(){
	int n,e;
	cin>>n>>e;
	int **adjmatrix=new int*[n];
	for(int i=0;i<n;i++)
		adjmatrix[i]=new int[n];
	int u,v,d;
	for(int i=0;i<e;i++){
		cin>>u>>v>>d;
		adjmatrix[u][v]=d;
		adjmatrix[v][u]=d;
	}
	
	prims(adjmatrix,n);
	return 0;
}
