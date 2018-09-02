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
int MaxElement(Node *root)
{
	if(root ==NULL)
		return 0;
	int lmax=MaxElement(root->left);
	int cmax=root->data;
	int rmax=MaxElement(root->right);
	
	if(lmax > cmax && lmax>rmax)
		return lmax;
	else if(cmax>lmax && cmax>rmax)
		return cmax;
	else
		return rmax;
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
	cout<<"\n Maximun = :"<<MaxElement(root);;
	return 0;
}
//Time Complexity =O(n) and Space Complexity O(n)
