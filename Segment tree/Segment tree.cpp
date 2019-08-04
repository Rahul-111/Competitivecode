#include<bits/stdc++.h>
using namespace std;
void buildTree(int *tree,int *a,int index,int s,int e){
	
	//Base case
	if(s>e){
		return;
	}
	
	//base case at leaf node
	if(s==e){
		tree[index]=a[s];
		return;
	}
	
	int mid=(s+e)/2;
	//Build left subtree
	buildTree(tree,a,2*index,s,mid);
	//Build right subtree
	buildTree(tree,a,2*index+1,mid+1,e);
	
	int left=tree[2*index];
	int right=tree[2*index+1];
	
	tree[index]=min(left,right);
}

int query(int *tree,int index,int s,int e,int qs,int qe){
	/// 3 cases
	/// 1. No overlap
	if(qs>e || qe<s){
		return INT_MAX;
	}
	
	///2.Complete Overlap
	if(s>=qs && e<=qe){
		return tree[index];
	}
	
	int mid=(s+e)/2;
	int leftAns=query(tree,2*index,s,mid,qs,qe);
	int rightAns=query(tree,2*index+1,mid+1,e,qs,qe);
	
	return min(leftAns,rightAns);	
}
void updateNode(int *tree,int index,int s,int e,int i,int value){
	//No overlap
	if(i<s || i>e)
		return ;
	// reached leaf node
	if(s==e){
		tree[index]=value;
		return;
	}
	
	//Lying in Rnage -i is lying between s and e
	int mid=(s+e)/2;
	updateNode(tree,2*index,s,mid,i,value);
	updateNode(tree,2*index+1,mid+1,e,i,value);
	
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}
//Range Update
/// You will be given a range rs and re,
// and you increment every element in the range by a value inc

void updateRange(int *tree,int index,int s,int e,int rs,int re,int value){
	//No overlap
	if(re<s || rs>e){
		return ;
	}
	//Reached Leaf Node
	if(s==e){
		tree[index] +=value;
		return;
	}
	int mid=(s+e)/2;
	updateRange(tree,2*index,s,mid,rs,re,value);
	updateRange(tree,2*index+1,mid+1,e,rs,re,value);
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return ;
}
int main(){
	int arr[]={1,4,-2,3};
	int n=6;//sizeof(arr)/sizeof(int);
	
	int *tree = new int[4*n+1];
	int index=1;
	int s=0;
	int e=n-1;
	buildTree(tree,arr,index,s,e);//O(n)
	
	
	int no_of_q;
	cin>>no_of_q;
	
//	updateNode(tree,index,s,e,2,4); //O(logn)
	
	updateRange(tree,index,s,e,1,2,4);//O(n) in worst case
	
	while(no_of_q--){
		int qs,qe;
		cin>>qs>>qe;
		cout<<"Min value between range is";
		cout<<query(tree,1,s,e,qs,qe)<<endl;//O(logn)
	}
	return 0;
}
