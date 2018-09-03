#include<iostream>
#include<queue>

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

void levelOrder(Node * root)
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
			q.push(node->left);	
		if(node->right !=NULL)
			q.push(node->right);	
	}		
}

int FullNodes(Node * root)
{
	if(root == NULL)
		return 0;
	queue<Node *> q;
	int count=0;
	q.push(root);
	while(q.empty() == false)
	{
		Node * node = q.front();
		q.pop();
		if(!root->left && root->right || !root->right && root->left)
			count++;
		if(node->left !=NULL)
				q.push(node->left);	
		if(node->right !=NULL)
				q.push(node->right);
	}		
	return count;
}
int halfNodes(Node *root)
{
	if(root==NULL)
		return 0;
	int count =0;
	if(!root->left && root->right || !root->right && root->left)
		count ++;
	count+= halfNodes(root->left) + halfNodes(root->right);
	return count;
}
int main()
{
	Node *root = newNode(7);
	root->left=newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right= newNode(9);
	cout<<"Levelorder traversal :\n";levelOrder(root);
	cout<<"\n full Nodes "<<halfNodes(root);
	return 0;
}
