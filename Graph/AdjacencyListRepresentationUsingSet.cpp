#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
struct Graph{
	int V;
	set<int, greater<int> >* adjList;
};
struct Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V=V;
	
	graph->adjList=new set<int, greater<int> >[V];
	return graph;
}
void addEdge(Graph *graph,int src,int dest)
{
	graph->adjList[src].insert(dest);
	graph->adjList[dest].insert(src);
}
void printGraph(Graph *graph)
{
	for(int i=0;i<graph->V;i++)
	{
		set<int,greater<int> > lst = graph->adjList[i];
		cout<<endl<<"Adjacency list of vertex "<<i<<endl;
		
		for(set<int,greater<int> >::iterator it=lst.begin();it!=lst.end();it++)
			cout<<*it<<" ";
		cout<<endl;	
	}	
}
void searchEdge(Graph *graph,int src,int dest)
{
	set<int,greater<int> >::iterator it;
	it=graph->adjList[src].find(dest);
	if(it==graph->adjList[src].end())
		cout<<endl<<"Edge from "<<src<<" to "<<dest<<" not found."<<endl;
	else
		cout<<endl<<"Edge from "<<src<<" to "<<dest<<" found."<<endl;
}
// Driver code 
int main() 
{ 
    // Create the graph given in the above figure 
    int V = 5; 
    struct Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
  
    // Print the adjacency list representation of 
    // the above graph 
    printGraph(graph); 
  
    // Search the given edge in the graph 
    searchEdge(graph, 2, 1); 
    searchEdge(graph, 0, 3); 
  
    return 0; 
} 
