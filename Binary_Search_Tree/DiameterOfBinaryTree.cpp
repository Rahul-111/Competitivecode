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
int height(Node* node)
{
   /* base case tree is empty */
   if(node == NULL)
       return 0;
 
   /* If tree is not empty then height = 1 + max of left 
      height and right heights */   
   return 1 + max(height(node->left), height(node->right));
} 
int diameter(Node * tree)
{
   /* base case where tree is empty */
   if (tree == NULL)
     return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(tree->left);
  int rheight = height(tree->right);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
} 
int Diameter(Node *root,int *dia)
{
	int left,right;
	if(root==NULL)
		return 0;
	left = Diameter(root->left,dia);
	right= Diameter(root->right,dia);
	
	//int max_dia= left + right +1;
	//*dia = max(*dia , max_dia);
	if(left+right+1>*dia)
		*dia=left+right+1;
	return max(left,right) +1;
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
	int dia=1;
	Diameter(root,&dia);
	cout<<"\nDiameter of a tree  "<<dia;
	cout<<"\nDiameter of a tree  "<<diameter(root);
	return 0;
}
