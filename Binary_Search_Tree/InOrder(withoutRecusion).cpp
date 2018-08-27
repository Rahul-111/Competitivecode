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
void InOrder(Node *root)
{
	stack<Node *> S;
	Node *curr = root;
	while(curr !=NULL || S.empty() == false)
	{
		while(curr!=NULL)
		{
			S.push(curr);
			curr=curr->left;
		}
	
	curr = S.top();
	S.pop();
	cout<<curr->data<<"  ";
	curr=curr->right;
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
	cout<<"Inorder traversal :\n";InOrder(root);
	return 0;
}
