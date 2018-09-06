#include<iostream>
#include<stack>
#include<queue>
using namespace std;
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
void levelOrder(Node *root)
{
	if(root==NULL)
		return ;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp=q.front();
		cout<<temp->data<<"  ";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}
void zigZag(Node *root)
{
	stack<Node *> currentlevel;
	stack<Node *> nextlevel;
	
	currentlevel.push(root);
	bool lefttoright=true;
	while(!currentlevel.empty())
	{
		Node *temp=currentlevel.top();
		currentlevel.pop();
		if(temp)
		{
			cout<<temp->data<<"  ";
			if(lefttoright)
			{
				if(temp->left)
					nextlevel.push(temp->left);
				if(temp->right)
					nextlevel.push(temp->right);
			}
			else{
				if(temp->right)
					nextlevel.push(temp->right);
				if(temp->left)
					nextlevel.push(temp->left);
			}
		}
		if(currentlevel.empty())
		{	
			lefttoright=!lefttoright;
			swap(currentlevel,nextlevel);
		}
	}
}
int main()
{
	Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"\n Levelorder traveersal  of tree\n";
	levelOrder(root);
	cout << "\n ZigZag Order traversal of binary tree is \n";
	zigZag(root);
	return 0;
}
