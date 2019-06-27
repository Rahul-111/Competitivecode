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
			cout<<t->data<<" ";
			Q.pop();
			if(t->left)
				Q.push(t->left);
			if(t->right)
				Q.push(t->right);
			size--;	
		}
		cout<<endl;
	}
}
void RightView(Node *root,int level,int *max_level){
	if(root==NULL)
		return;
	if(*max_level<level){
		cout<<root->data<<endl;
		*max_level=level;
	}
	RightView(root->right,level+1,max_level);
	RightView(root->left,level+1,max_level);
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
	cout<<"Right View Using Recursion"<<endl;
	int max_level=0;
	RightView(root,1,&max_level);
	return 0;
}
