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
int levelThatHasMaxSum(Node *root)
{
	if(root==NULL)
		return 0;
	queue<Node *> q;
	q.push(root);
	q.push(NULL);
	int currentsum=0,maxsum=0,maxlevel=0;
	int level=0;
	while(q.empty()==false)
	{
		Node *node=q.front();
		q.pop();
		if(node==NULL)
		{
			if(q.empty()==false)
				q.push(NULL);
			level++;
			if(currentsum>maxsum)
			{
				maxsum=currentsum;
				maxlevel=level;
			}
			currentsum=0;
			
		}
		else{
			currentsum +=node->data;
		if (node->left != NULL)
            q.push(node->left);
 
        if (node->right != NULL)
            q.push(node->right);
		}
	}
	return maxlevel;
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
	cout<<"Level : "<<levelThatHasMaxSum(root);
}
