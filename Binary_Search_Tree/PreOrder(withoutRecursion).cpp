#include<iostream>
#include<stack>

using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};

Node * newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->right=temp->left=NULL;
	return temp;
}
void preOrder(Node *root)
{
	if(root == NULL)
		return ;
	
	stack<Node *> S;
	S.push(root);
	while(S.empty() == false)
	{
		Node *node = S.top();
		cout<<node->data<<"  ";
		S.pop();
		
		if(node->right)
			S.push(node->right);
		if(node->left)
			S.push(node->left);
	}
}
int main()
{
	Node *root = newNode(7);
	root->left=newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right= newNode(9);
	cout<<"PreOrder traversal :\n";preOrder(root);
	return 0;
}
