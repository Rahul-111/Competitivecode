#include<iostream>
#include<queue>
using namespace std;
void printfDFS(int **edge,bool *visited,int n,int st){
	cout<<st<<" ";
	visited[st]=true;
	for(int i=0;i<n;i++){
		if(st==i)
			continue;
		if(!visited[i] && edge[st][i]==1)
		printfDFS(edge,visited,n,i);
	}
}
void printfBFS(int **edge,bool *visited,int n,int st){
	queue<int> Q;
	Q.push(st);
	visited[st]=true;
	while(!Q.empty()){
		int currentNode = Q.front();
		Q.pop();
		cout<<currentNode<<" ";
		for(int i=0;i<n;i++){
			if(currentNode==i){
				continue;
			}
			if(!visited[i]&& edge[currentNode][i]==1){
				Q.push(i);
				visited[i]=true;	
			}
		}
	}
}
void BFS(int **edge,int n){
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)	visited[i]=false;
	cout<<"BFS"<<endl;
	for(int i=0;i<n;i++){
		if(!visited[i])
			printfBFS(edge,visited,n,i);	
	}
}
void DFS(int **edge,int n){
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)	visited[i]=false;
	cout<<"DFS"<<endl;
	for(int i=0;i<n;i++){
		if(!visited[i])
			printfDFS(edge,visited,n,i);	
	}
}
int main(){
	int n;
	int e;
	cin>>n>>e;
	int **edge = new int*[n];
	for(int j=0;j<n;j++){
		edge[j] = new int[n];
	}
	int s,f;
	for(int j=0;j<e;j++){
		cin>>s>>f;
		edge[s][f]=1;
		edge[f][s]=1;
	}
	BFS(edge,n);
	DFS(edge,n);
	for(int i=0;i<n;i++){
		delete [] edge[i];
	}
	delete [] edge;
	return 0;
}
