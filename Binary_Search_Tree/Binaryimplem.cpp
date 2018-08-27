#include<iostream>
using namespace std;
struct Node
{	int data;
	struct Node *left,*right;
};
//O(w*n) w=width , n =  node
//O(n*n) worst case
void inOrder(Node * root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<"  ";
		inOrder(root->right);
	}
}
void preOrder(Node * root)
{
	if(root)
	{
		cout<<root->data<<"  ";
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(Node * root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<"  ";
	}
}
void printLevelOrder(Node *root,int level)
{
	if(root==NULL)
		return ;
	if(level == 1)
		cout<<root->data<<"  ";
	else{
		printLevelOrder(root->left,level-1);
		printLevelOrder(root->right,level-1);
	}
}
int height(Node * root)
{
	if(root==NULL)
		return 0;
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);
	
		if(lheight>rheight)
			return lheight+1;
		return rheight+1;
	}
}
void levelOrder(Node *root)
{
	int h = height(root);
	int i;
	for(int i=1;i<=h;i++)
		{
			printLevelOrder(root,i);
			cout<<endl;
		}
}
Node * newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->right=temp->left=NULL;
	return temp;
}
int main()
{
	Node *root = newNode(7);
	root->left=newNode(5);
	root->right = newNode(8);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right= newNode(9);
	cout<<"Inorder traversal :\t";inOrder(root);
	cout<<endl;
	cout<<"Preorder traversal :\t";preOrder(root);
	cout<<endl;
	cout<<"Postorder traversal :\t";postOrder(root);
	cout<<endl;
	cout<<"Levelorder traversal :\n";levelOrder(root);
	return 0;
}
