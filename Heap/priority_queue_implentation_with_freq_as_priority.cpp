#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int freq;
	char c;
};
struct compare{
	bool operator()(Node &l,Node &r){
	return l.freq<r.freq;
	}	
};

int main(){
	priority_queue<Node,vector<Node>,compare> pq_fre;
//	Node p;
//	p.c='a';
//	p.freq=4;
//	pq_fre.push(p);
	
	Node q;
	q.c='b';
	q.freq=5;
	pq_fre.push(q);
	
	Node r;
	r.c='c';
	r.freq=2;
	pq_fre.push(r);
	
	Node s;
	s.c='d';
	s.freq=1;
	pq_fre.push(s);
	
	Node p;
	p.c='a';
	p.freq=4;
	pq_fre.push(p);
	
	Node a;
	a.c='z';
	a.freq=55;
	pq_fre.push(a);
	while(!pq_fre.empty()){
		Node x=pq_fre.top();
		cout<<x.c<<" -> "<<x.freq<<endl;
		pq_fre.pop();
	}
	return 0;
}
