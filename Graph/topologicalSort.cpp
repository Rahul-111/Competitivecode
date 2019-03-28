#include<bits/stdc++.h>
using namespace std;
void showGraph(vector<vector<int > > V,int n){
	for(int i=0;i<n;i++){
		cout<<i<<" ";
		for(auto j:V[i])
			cout<<"-->"<<j;
		
		cout<<endl;
	}
}
void topologycalUtil(vector<vector<int > > V,int v,bool *visited,stack<int > &st){
	visited[v]=true;
	for(auto j:V[v]){
		if(!visited[j])
			topologycalUtil(V,j,visited,st);
	}
	st.push(v);
}
void topologySort(vector<vector<int > > V,int n){
	stack<int > st;
	bool *visited = new bool[n];
	for(int i=0;i<n;i++)	visited[i]=false;
	
	for(int i=0;i<n;i++){
		if(visited[i]==false)
			topologycalUtil(V,i,visited,st);
	}
	
	while(st.empty()==false){
		cout<<st.top()<<" ";
		st.pop();
	}
}
int main(){
	int n,e;
	cin>>n>>e;
	vector<vector<int > > V{n};
	
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		V[x].push_back(y);
	}
	
	bool *visited=new bool[n];
	for(int i=0;i<n;i++)	visited[i]=false;
	topologySort(V,n);
	//showGraph(V,n);
	return 0;
}
