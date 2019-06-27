#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *left,*right;
};
Node *newNode(int x){
	Node *temp=new Node();
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void levelOrder(Node *root){
	queue<Node *> Q;
	Q.push(root);
	while(!Q.empty()){
		int size=Q.size();
		while(size>0){
			Node *t=Q.front();
			Q.pop();
			cout<<t->data<<" ";
			if(t->left)
				Q.push(t->left);
			if(t->right)
				Q.push(t->right);
			size--;
		}
		cout<<endl;
	}
}
void BottomView(Node *root){
	map<int,int> Map;
	int h=0;
	queue<pair<Node*, int> > Q; 
    Q.push(make_pair(root, h));
	
	while(!Q.empty()){
		pair<Node*,int> temp=Q.front();
		Node* t=temp.first;
		h=temp.second;
		Q.pop();
		Map[h]=t->data;
		
		if(t->left!=NULL)
			Q.push(make_pair(t->left,h-1));
		if(t->right!=NULL)
			Q.push(make_pair(t->right,h+1));
	} 
	
	cout<<"Bottom View:"<<endl;
	for(auto i=Map.begin();i!=Map.end();i++){
		cout<<i->second<<" ";
	}
}
int main(){
	Node *root;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"Level Order"<<endl;
	levelOrder(root);
	cout<<"Bottom view of a Binary Tree "<<endl;
	BottomView(root);
	return 0;
}
