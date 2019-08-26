#include<iostream>
#include<queue>
using namespace std;
int KthSmallestElement(int input[],int n,int k){
	priority_queue<int> pq;	//max heap
	for(int i=0;i<k;i++){
		pq.push(input[i]);
	}		
	
	for(int i=k;i<n;i++){
		if(input[i] < pq.top()){
			pq.pop();
			pq.push(input[i]);
		}
	}
	
	int ans=pq.top();
	return ans;
}
int main(){
	int input[]={8,5,12,10,0,1,6,9};
	int n=sizeof(input)/sizeof(input[0]);
	int k=4;
	cout<<"kth smallest element is "<<KthSmallestElement(input,n,k);
	return 0;
}
