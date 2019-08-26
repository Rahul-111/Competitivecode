#include<bits/stdc++.h>
using namespace std;
class PriorityQueue{
	vector<int> pq;
	public:
		PriorityQueue(){
			
		}
		
		bool isEmpty(){
			return pq.size()==0;
		}
		
		int getMin(){
			if(isEmpty()){
				return 0; //priority Queue is empty
			}
			return pq[0];
		}
		
		void insert(int element){
			pq.push_back(element);
			
			int childIndex=pq.size()-1;
			while(childIndex>0){
				int parentIndex=(childIndex-1)/2;
				if(pq[childIndex]<pq[parentIndex]){
					int temp=pq[childIndex];
					pq[childIndex]=pq[parentIndex];
					pq[parentIndex]=temp;
				}
				else{
					break;
				}
				childIndex=parentIndex;
			}
		}
		int removeMin(){
			if(isEmpty())
				return -1;//to indicate stack is empty
			//swap root node with last node
			int ans=pq[0];
			pq[0]=pq[pq.size()-1];
			
			//delete last element
			pq.pop_back();
			
			//heapify from root to leaf
			int parentIndex=0;
			int leftChild,rightChild,minIndex;
			
			leftChild=2*parentIndex+1;
			rightChild=2*parentIndex+2;
		
			while(leftChild <pq.size()){
				
				minIndex=parentIndex;		
				if(pq[leftChild] < pq[minIndex])
					minIndex=leftChild;
				if(pq[rightChild]<pq[minIndex] && rightChild<pq.size())
					minIndex=rightChild;
				if(minIndex == parentIndex)
					break;
				// parent with minIndex
				int temp=pq[minIndex];
				pq[minIndex]=pq[parentIndex];
				pq[parentIndex]=temp;
				
				parentIndex=minIndex;
				leftChild=2*parentIndex+1;
				rightChild=2*parentIndex+2;
				
			}
				
			return ans;
		}
		void display(){
			cout<<"\n";
			for(auto x:pq){
				cout<<x<<" ";
			}
		}
};
int main(){
	cout<<"Hello"<<endl;
	PriorityQueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);
	
//	p.display();
	cout<<p.getMin()<<endl;
	while(!p.isEmpty()){
		cout<<p.removeMin()<<" ";
	}
	cout<<endl;
	return 0;
}
