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
Node* search(Node *root,int data)
{
	if(root == NULL)
		return NULL;
	else if(root->data > data)
		return search(root->left,data);
	else if(root->data<data) 
		return search(root->right,data);
	else return root;
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
	x=search(root,5);
	if(x == NULL)
		cout<<"Match Not Found";
	else cout<<"Match found";
	return 0;
}
