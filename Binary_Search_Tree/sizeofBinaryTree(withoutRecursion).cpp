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
void Insert(Node * root,int data)
{
	if(root == NULL)
		return ;
	queue<Node *> q;
	
	q.push(root);
	while(q.empty() == false)
	{
		Node * node = q.front();

		q.pop();
		
		if(node->left !=NULL){
			q.push(node->left);	
		}	
		else{
			node->left=newNode(data);
		}
		if(node->right !=NULL){
			q.push(node->right);
		}
		else{
			node->right=newNode(data);
		}
	
	}		
}
int sizeofBinaryTree(Node *root)
{
	int size=0;
	if(root == NULL)
		return 0;
	queue<Node *> q;
	
	q.push(root);
	while(q.empty() == false)
	{
		Node * node = q.front();

		q.pop();
		
		if(node->left !=NULL){
			q.push(node->left);
			size++;
		}
		if(node->right !=NULL){
			q.push(node->right);
			size++;
		}
	}
	return size+1;		
}
Node *insert(Node *root,int data)
{
	if(root==NULL)
		return newNode(data);
	else
		root->left=insert(root->left,data);
	return root;
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
	cout<<"\n Size of Binary tree "<<sizeofBinaryTree(root);
	insert(root,10);
	insert(root,12);
	cout<<"\nInorder traversal :\n";InOrder(root);
	cout<<"\n Size of Binary tree "<<sizeofBinaryTree(root);
	return 0;
}
