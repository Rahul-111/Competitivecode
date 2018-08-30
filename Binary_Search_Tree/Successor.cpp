#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left,*right,*parent;
};
Node *newNode(int data)
{
	Node *temp=new Node;
	temp->data = data;
	temp->left = temp->right =temp->parent=NULL;
	return temp;
}
void inorder(Node *t)
{
	if(t==NULL)
		return ;
	else
	{
		inorder(t->left);
		cout<<t->data<<"  ";
		inorder(t->right);
	}
}
Node * Find_min(Node *x)
{
	if(x->left ==NULL)
		return x;
	Find_min(x->left);
}

Node * insert(Node *node,int data)
{
	if(node ==NULL)
		return newNode(data);
	else{
		Node *temp;
		if(data <= node->data)
		{
			temp=insert(node->left,data);
			node->left=temp;
			temp->parent=node;
		}
		else
		{
			temp=insert(node->right,data);
			node->right=temp;
			temp->parent=node;
		}
		return node;
	}
}
Node *successor(Node *x)
{
	if(x->right !=NULL)
		return Find_min(x->right);
	Node *y =x->parent;
	while(y!=NULL && x ==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
int main()
{	
	cout<<"Tree node:\t";
	Node *root=NULL;
	root=insert(root,15);
	root=insert(root,6);
	root=insert(root,18);
	root=insert(root,3);
	root=insert(root,7);
	root=insert(root,17);
	root=insert(root,20);
	root=insert(root,2);
	root=insert(root,4);
	root=insert(root,13);
	root=insert(root,9);
	Node *x= root;
	inorder(x);
	x=root->left->right->right;
	cout<<"\n Successor of "<<x->data<<"  is ";
	Node *s=successor(x);
	cout<<s->data<<"  ";
	return 0;
}
