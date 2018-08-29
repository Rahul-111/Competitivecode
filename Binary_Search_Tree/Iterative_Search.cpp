#include<iostream>
using namespace std;

struct Node{
	int data;
	Node * left,*right;
};

Node * newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->left = temp->right= NULL;
	return temp;
}
void preorder(Node *root)
{
	if(root)
	{
		cout<<root->data<<"  ";
		preorder(root->left);
		preorder(root->right);
	}
}
Node * Iterative_search(Node *root,int k)
{
	while( root !=NULL && k !=root->data)
	{
		if(k < root->data)
			root=root->left;
		else
			root=root->right;
	}
	return root; 
}
int main()
{
	Node *root = newNode(15);
	root->left=newNode(6);
	root->right=newNode(18);
	root->left->left=newNode(3);
	root->left->right = newNode(7);
	root->right->left = newNode(17);
	root->right->right = newNode(20);
	//preorder(root);
	Node *x;
	x=Iterative_search(root,17);
	if(x == NULL)
		cout<<"Match Not Found";
	else cout<<"Match found";
	return 0;
}
