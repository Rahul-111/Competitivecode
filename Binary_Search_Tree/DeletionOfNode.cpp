#include<iostream>
using namespace std;
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};
Node * newNode(int data)
{
	Node *temp=new Node;
	temp->data=data;
	temp->left = temp->right=NULL;
	return temp;
}
//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
Node* Insert(Node *root,int data) {
	/*if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}*/
	if(root==NULL)
		return newNode(data);
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
void Inorder(Node *root) {
	if(root == NULL) return;
 
	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}
Node * Delete(Node *root,int data)
{
	if(root==NULL)
		return root;
	else if(root->data > data) root->left =Delete(root->left,data);
	else if(root->data < data) root->right = Delete(root->right,data);
	
	else{
		//Case 1:No Child 
		if(root->left ==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
			}
		//Case 2: One child 
		else if (root->left ==NULL)
		{
			Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else{
			Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
int main()
{
	Node* root = NULL;
	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,3); 
	root = Insert(root,4); 
	root = Insert(root,1); 
	root = Insert(root,11);
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	root = Delete(root,5);
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
