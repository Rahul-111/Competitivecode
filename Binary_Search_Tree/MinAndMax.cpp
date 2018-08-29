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
Node * Find_Min(Node *root)
{
	if(root->left == NULL)
		return root;
	Find_Min(root->left);
}
Node * Find_Max(Node *root)
{
	if(root->right == NULL)
		return root;
	Find_Max(root->right);
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
	//x=Find_Min(root);
	x = Find_Max(root);
	cout<<x->data;
	return 0;
}
