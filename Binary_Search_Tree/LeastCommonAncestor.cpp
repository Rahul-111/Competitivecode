#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int data;
	Node *left,*right;
};

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void levelOrder(Node *root)
{
	if(root==NULL)
		return ;
		
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp=q.front();
		cout<<temp->data<<"   ";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}
Node *leastCommonAncestor(Node *root,int d1,int d2)
{
	if(root==NULL)
		return NULL;
	if(root->data==d1 || root->data==d2)
		return root;
		
	Node *left_lca=leastCommonAncestor(root->left,d1,d2);
	Node *right_lca=leastCommonAncestor(root->right,d1,d2);
	
	if(left_lca && right_lca)
		return root;
		
	 return (left_lca != NULL)? left_lca: right_lca;
}
int main()
{
	Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	levelOrder(root);
	Node *lca=leastCommonAncestor(root,4,8);
	if(lca)
		cout<<"Ancestor is "<<lca->data;
	else
		cout<<"Do not exist";
	return 0;
}
