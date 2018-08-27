#include<iostream>
/*
Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. 
So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
*/


using namespace std;
struct Node
{	int data;
	struct Node *left,*right;
};
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
	cout<<"Levelorder traversal :\n";levelOrder(root);
	return 0;
}
