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
void printArray(int path[],int pathlen)
{
	cout<<endl;
	int sum=0;
	for(int i=0;i<pathlen;i++)
	{
		cout<<path[i]<<"  ";
	}
}
void printrecursion(Node *root,int path[],int pathlen)
{
	if(root==NULL)
		return ;
	//append this node to the path array
	path[pathlen]=root->data;
	pathlen++;
	if(root->left==NULL && root->right==NULL)
		printArray(path,pathlen);
	else{
		printrecursion(root->left,path,pathlen);
		printrecursion(root->right,path,pathlen);
	}
}
void printroottoleaf(Node *root)
{
	int path[100];
	printrecursion(root,path,0);
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
	printroottoleaf(root);
}
