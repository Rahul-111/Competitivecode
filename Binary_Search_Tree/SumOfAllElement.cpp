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
//WithRecursion
int Sum(Node *root)
{
	if(root==NULL)
		return 0;
	return (root->data+Sum(root->left)+Sum(root->right));
}
//WithOutRecusion
int Sm(Node *root)
{
	if(root==NULL)
		return 0;
	queue<Node *> q;
	q.push(root);
	int sum=0;
	while(!q.empty())
	{
		Node *node=q.front();
		q.pop();
		sum +=node->data;
		if(node->left)
			q.push(node->left);
		if(node->right)
			q.push(node->right);
	}
	return sum;
}
int main()
{	
	cout<<"Tree node:\t";
	Node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5);
	Node *x=root;
	levelOrder(root);
	cout<<"Sum = "<<Sm(root);
}
