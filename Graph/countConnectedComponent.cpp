#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Graph{
	int V;
	list<int> *adj;
	void fillOrder(int v,bool visited[],stack<int> &stack);
	void DFSUtil(int v,bool visited[]);
	
	public:
		Graph(int V);
		void addEdge(int v,int w);
		void printSCCs();
		Graph getTranspose();
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::DFSUtil(int v,bool visited[]){
	visited[v]=true;
	cout<<v<<" ";
	
	for(auto i:adj[v]){
		if(!visited[i])
			DFSUtil(i,visited);
	}
}
Graph Graph::getTranspose(){
	Graph g(V);
	for(int i=0;i<V;i++){
		for(auto j:adj[i]){
			g.adj[j].push_back(i);
		}
	}
	return g;
}
void Graph::addEdge(int v,int w){
	adj[v].push_back(w);
}
void Graph::fillOrder(int v,bool visited[],stack<int> &stack){
	visited[v]=true;
	for(auto i:adj[v]){
		if(!visited[i])
			fillOrder(i,visited,stack);
	}
	stack.push(v);
}
void Graph::printSCCs(){
	stack<int > stack;
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
		
	for(int i=0;i<V;i++){
		if(!visited[i])
			fillOrder(i,visited,stack);
	}
	
	Graph gr=getTranspose();
	
	for(int i=0;i<V;i++)
		visited[i]=false;
	
	int countConnected=0;	
	while(!stack.empty()){
		int v=stack.top();
		stack.pop();
		
		if(!visited[v]){
			gr.DFSUtil(v,visited);
			countConnected++;
			cout<<endl;
		}
	}
	
	cout<<"Number of Connected Component are "<<countConnected<<endl;
}
int main(){
	// Create a graph given in the above diagram 
    Graph g(5); 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are strongly connected components in "
            "given graph \n"; 
    g.printSCCs(); 
  
}
