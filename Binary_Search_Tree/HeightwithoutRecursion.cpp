#include<iostream>
#include<queue>
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
void LevelOrder(Node * root)
{
	if(root == NULL)
		return ;
	queue<Node *> q;
	
	q.push(root);
	while(q.empty() == false)
	{
		Node * node = q.front();
		cout<<node->data<<"  ";
		q.pop();
		
		if(node->left !=NULL)
		{
			q.push(node->left);	
		}	
		
		if(node->right !=NULL)
		{
			q.push(node->right);
		}
	}		
}
void deleteTree(Node *root)
{
	if(root==NULL)
		return ;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}
int height(Node *root)
{
	if(root == NULL)
		return -1;
	queue<Node *> q;
	int level=-1;
	q.push(root);
	q.push(NULL);
	while(q.empty() == false)
	{
		Node * node = q.front();
		q.pop();
		if(node==NULL)
		{
			if(q.empty()==false)
				q.push(NULL);	
			level++;
		}
		else
		{
			if(node->left !=NULL)
				q.push(node->left);		
			if(node->right !=NULL)
				q.push(node->right);
		}
	}
	return level;
}
int main()
{
	Node *root = newNode(7);
	root->left=newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right= newNode(9);
	cout<<"Level Order Traversal :  ";LevelOrder(root);
	cout<<"\nHeight of a tree "<<height(root);
	return 0;
}
