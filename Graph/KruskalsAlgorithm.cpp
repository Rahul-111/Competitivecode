#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int src,dest,weight;
};
bool compare(Edge &l,Edge &b){
	return l.weight < b.weight;
}
int find(int *parent,int x){
	if(parent[x]==x)
		return x;
	else
		return find(parent,parent[x]);
}
void Union(int *parent,int u,int v){
	int xset=find(parent,u);
	int yset=find(parent,v);
	if(xset!=yset){
		parent[xset]=yset;
	}
}
//wrong implementation
bool checkParent(int u,int v,int *parent){
	 if(find(parent,u)!=find(parent,v)){
	 	Union(parent,u,v);
	 	return true;
	 }
	 return false;
}
int main(){
	int n,e;
	cin>>n>>e;
	
	Edge *adjList=new Edge[e];
	int u,v,d;
	cout<<"Enter src , dest and weight"<<endl;
	for(int i=0;i<e;i++){
		cin>>u>>v>>d;
		adjList[i].src=u;
		adjList[i].dest=v;
		adjList[i].weight=d;
	}
	sort(adjList,adjList+e,compare);
	cout<<"Sorted graph based on weight "<<endl;
	for(int i=0;i<e;i++){
		
		cout<<adjList[i].src<<"  ";
		cout<<adjList[i].dest<<"  ";
		cout<<adjList[i].weight<<"  ";
		cout<<endl;
	}
	
	Edge *output=new Edge[n-1];
	int count=0,i=0;
	int *parent=new int[n];
	for(int i=0;i<n;i++)	parent[i]=i;
	while(count<n-1){
		if(checkParent(adjList[i].src,adjList[i].dest,parent)){
			output[count].dest=adjList[i].dest;
			output[count].src=adjList[i].src;
			output[count].weight=adjList[i].weight;
			count++;
		}
		i++;
	}
	
	cout<<"Output graph "<<endl;
	for(int i=0;i<n-1;i++){
		
		cout<<output[i].src<<"  ";
		cout<<output[i].dest<<"  ";
		cout<<output[i].weight<<"  ";
		cout<<endl;
	}
	//time complexity O(ElogE+V*E)
	//VE cycle detection O(V*O(log)).
	return 0;
}
