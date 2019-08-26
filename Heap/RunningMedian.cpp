#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void add(int x,priority_queue<int> &h,priority_queue<int,vector<int>,greater<int>> &l){
    // min_head is empty or x < root_of_max_heap
    if(h.size()==0 || x < h.top()){
        h.push(x);
    }else{
        l.push(x);
    }
}
void rebalance(priority_queue<int> &h,priority_queue<int,vector<int>,greater<int>> &l){
	if( h.size() == l.size()+2){
		l.push(h.top());
		h.pop();
	}
	else if(l.size() == h.size()+2 ){
		h.push(l.top());
		l.pop();		
	}
}
int getMedian(priority_queue<int> &h,priority_queue<int,vector<int>,greater<int>> &l){
	if(l.size() == h.size()){
		return (l.top()+h.top())/2;
	}
	else if(l.size()==h.size()+1){
		return l.top();
	}
	else if(h.size()==l.size()+1){
		return h.top();
	}
}
int main()
 {
	//code
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	priority_queue<int> max_heap;
	while(n--){
	    int x;
	    cin>>x;
	    add(x,max_heap,min_heap);
	    rebalance(max_heap,min_heap);
	    cout<<getMedian(max_heap,min_heap)<<endl;
	}
// 	while(!min_heap.empty()){
// 	    min_heap.pop();
// 	}
// 	while(!max_heap.empty()){
// 	    max_heap.pop();
// 	}
	return 0;
}
