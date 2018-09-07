#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->data<<"  ";
		inorder(root->right); 
	}
}
bool ancestor(Node *root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	if(ancestor(root->left,data) || ancestor(root->right,data))
	{
		cout<<root->data<<"  ";
		return true;
	}
	return false;
}
int main()
{
	Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right=newNode(3);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	inorder(root);
	cout<<"\n Ancestor are ";
	ancestor(root,7);
}
