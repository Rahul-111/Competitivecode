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
int HasPathSum(Node *root,int sum)
{
	if(root==NULL)
		return(sum==0);
	else{
		int remainingSum=sum-root->data;
		
		if(root->left && root->right || (!root->left && !root->right))
			return (HasPathSum(root->left,remainingSum) || HasPathSum(root->right,remainingSum));
		else if(root->left)
			return HasPathSum(root->left,remainingSum);
		else
			return HasPathSum(root->right,remainingSum);
	}
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
	if(HasPathSum(root,7))
		cout<<"Exist";
	else cout<<"Not Exist";
}
