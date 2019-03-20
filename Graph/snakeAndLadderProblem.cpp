#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int > *adjList;
	public:
	Graph(int v){
		V=v;
		adjList = new list<int >[V];
	}
	void addEdge(int u,int v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";
			for(int node:adjList[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src,int dest){
		queue<int > q;
		bool *visited = new bool[V]{0};
		int *distance=new int[V]{0};
		int *parent=new int[V];
		for(int i=0;i<V;i++){
			parent[i]=-1;
		}
		q.push(src);
		visited[src]=true;
		distance[src]=0;
		while(!q.empty()){
			int node=q.front();
			cout<<node<<" ";
			q.pop();
			
			for(int neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour]=true;
					distance[neighbour]=distance[node]+1;
					parent[neighbour]=node;
				}
			}
		}
		cout<<endl;
//		for(int i=0;i<V;i++){
//			cout<<i<<" node having dist "<<distance[i]<<endl;
//		}
		
		cout<<"Shortest distance is "<<distance[dest]<<endl;
		cout<<"Shortest path is ";
		int temp=dest;
		while(temp!=-1){
			cout<<temp<<"<--";
			temp=parent[temp];
		}
	}
};
int main(){
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;
	
	Graph g(50);
	//insert edges
	for(int u=0;u<36;u++){
		for(int dice=1;dice<=6;dice++){
			int v=u+dice+board[u+dice];
			g.addEdge(u,v,false);
		}
	}
	g.bfs(0,36);
	return 0;
}
