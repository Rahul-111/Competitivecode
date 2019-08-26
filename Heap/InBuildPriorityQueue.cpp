#include<iostream>
#include <queue>
using namespace std;
int main(){
	priority_queue<int> pq;//bydefault it is max head
	
	pq.push(16);
	pq.push(1);
	pq.push(167);
	pq.push(7);
	pq.push(45);
	pq.push(32);
	
	cout<<"Size :"<<pq.size()<<endl;
	cout<<"Top : "<<pq.top()<<endl;
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	// min heap implementation
	priority_queue<int,vector<int>,greater<int>> p;
	p.push(16);
	p.push(1);
	p.push(167);
	p.push(7);
	p.push(45);
	p.push(32);
	
	cout<<"Size of min heap : "<<p.size()<<endl;
	cout<<"Top : "<<p.top()<<endl;
	
	while(!p.empty()){
		cout<<p.top()<<" ";
		p.pop();
	}
	cout<<endl;
	return 0;
}
