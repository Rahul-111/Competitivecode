#include<iostream>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left,*right,*parent;
};
Node *newNode(int data)
{
	Node *temp=new Node;
	temp->data = data;
	temp->left = temp->right =temp->parent=NULL;
	return temp;
}
// Utility function to do level order traversal
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
 
    queue<Node *> q;
    q.push(root);
 
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

Node * insert(Node *node,int data)
{
	if(node ==NULL)
		return newNode(data);
	else{
		Node *temp;
		if(data <= node->data)
		{
			temp=insert(node->left,data);
			node->left=temp;
			temp->parent=node;
		}
		else
		{
			temp=insert(node->right,data);
			node->right=temp;
			temp->parent=node;
		}
		return node;
	}
}
Node * leftRotation(Node *root,Node *x)
{
	Node *y=x->right;
	x->right=y->left;
	if (x->right != NULL)
        x->right->parent = x;
	y->left->parent=x;
	y->parent=x->parent;
	if(x->parent == NULL)
		root=y;
	else if(x==x->parent->left)
		x->parent->left=y;
	else
		x->parent->right=y;
	y->left=x;
	x->parent=y;
	return root;
}
int main()
{	
	cout<<"Tree node:\t";
	Node *root=NULL;
	root=insert(root,10);
	root=insert(root,6);
	root=insert(root,18);
	root=insert(root,12);
	root=insert(root,20);
	Node *x=root;
	Node *y=root;
	levelOrder(x);
	y=y->right;
	cout<<"data  "<<y->data<<"  ";
	root =leftRotation(root,y);
	cout<<"\nAfter rotation :  ";
	levelOrder(root);
	return 0;
}
