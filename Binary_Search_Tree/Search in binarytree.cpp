#include<iostream>
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
bool search(Node *root,int data)
{
	if(root!=NULL){
		if(root->data ==data)
			return true;
		else{
			return search(root->left,data) || search(root->right,data);
		}
	}
}
int findElementInTreeRecursive(struct binaryTreeNode * root, int num)
{
    // A variable for root value
    int root_val;
 
    // Variable to store values in left and right tree
    int left, right;
 
    if(root != NULL)
    {
        // Get the root value
        root_val = root -> data;
 
        if(root_val == num)
            return 1;
 
        // Find the element in left sub-tree
        // If found, we return 1
        left = findElementInTreeRecursive(root -> left, num);
        if(left == 1)
            return 1;
        else
        {
            // We need to find the element in right sub-tree
            right = findElementInTreeRecursive(root -> right, num);
            if(right == 1)
                return 1;
        }
    }
 
    // If we reach here, that means the element was not found
    return 0;
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
	if(search(root,3))
		cout<<"\nSearch Found";
	else
		cout<<"Search not Found";
	return 0;
}
