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
void leftViewLevel(Node *root){
	queue<Node *> Q;
	Q.push(root);
	while(!Q.empty()){
		int size=Q.size();
		int flag=0;
		while(size>0){
			Node *t=Q.front();
			if(flag==0){
				cout<<t->data<<" ";
				flag=1;
			}
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
void leftView(Node *root,int level,int *max_level){
	if(root==NULL)
		return;
	if(*max_level<level){
		cout<<root->data<<endl;
		*max_level=level;
	}
	leftView(root->left,level+1,max_level);
	leftView(root->right,level+1,max_level);
}
int main(){
	Node *root;
	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->right=newNode(4);
	root->left->right->right=newNode(5);
	root->left->right->right->right=newNode(6);
	cout<<"Level Order"<<endl;
	levelOrder(root);
	cout<<"Left View Using Level Order"<<endl;
	leftViewLevel(root);
	cout<<"Left View Using Recursion"<<endl;
	int max_level=0;
	leftView(root,1,&max_level);
	return 0;
}
