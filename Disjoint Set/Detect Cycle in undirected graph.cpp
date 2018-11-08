#include<iostream>
#include<stdlib>
using namespace std;
struct Edge
{
	int scr,dest;
};
struct Graph
{
	int V,E;
	struct Edge *edge;
};
struct Graph *createGraph(int V,int E)
{
	struct Graph graph=(struct Graph *)malloc(sizeof(struct Graph));
	//struct Graph graph=new struct Graph[sizeof(struct Graph)];
	graph->E=E;
	graph->V=V;
	graph->edge=(struct Edge *)malloc(graph->E*sizeof(struct Edge));
	//graph->edge=new struct Edge[graph->E * sizeof(struct Edge)]
	return graph;
}
// A utility function to find the subset of an element i
int find(int parent[],int i)
{
	if(parent[i]==-1)
		return i;
	else return find(parent,parent[i]);
}
// A utility function to do union of two subsets  
int Union(int parent[],int x,int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	if(xset!=yset)
	{
		parent[xset]=yset;
	}
}
// The main function to check whether a given graph contains  
// cycle or not 
int isCycle(struct Graph *graph)
{
	// Allocate memory for creating V subsets
	int *parent = (int*)malloc(graph->V*sizeof(int));
	// Initialize all subsets as single element sets 
    memset(parent, -1, sizeof(int) * graph->V); 
    // Iterate through all edges of graph, find subset of both 
    // vertices of every edge, if both subsets are same, then  
    // there is cycle in graph. 
    for(int i=0;i<graph->E;i++)
    {
    	int x=find(parent,graph->edge[i].scr);
    	int y=find(parent,graph->edge[i].dest);
    	if(x==y)
    		return 1;
    	Union(parent,x,y);
	}
	return 0;
}
int main()
{
	/* Let us create following graph 
         0 
        |  \ 
        |    \ 
        1-----2 */
    int V=3,E=3;
    struct Graph *graph=createGraph(V,E);
    
    graph->edge[0].scr=0;
    graph->edge[0].dest=1;
    
    graph->edge[1].scr=1;
    graph->edge[2].dest=2;
    
    graph->edge[2].scr=0;
    graph->edge[2].dest=2;
    
    if(isCycle(graph))
    	cout<<"Graph contain cycle";
    else
    	cout<<"Graph doesn't cantain cycle";
    
    return 0;
}
