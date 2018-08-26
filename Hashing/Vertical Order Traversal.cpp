#include<iostream>
using namespace std;
struct Node
{	int data;
	struct Node *left,*right;
};
//O(w*n) w=width , n =  node
//O(n*n) worst case
Node * newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->right=temp->left=NULL;
	return temp;
}
void findMinMax(Node *root,int *min,int *max,int hd)
{
	if(root == NULL)
		return ;
	
	if(hd < *min) *min = hd;
	else if(hd > *max) *max = hd;
	findMinMax(root->left,min,max,hd-1);
	findMinMax(root->right,min,max,hd+1);
}
void printVerticalLine(Node *root,int line_no,int hd)
{
	if(root == NULL)
		return ;
	if(hd==line_no)
		cout<<root->data<<"  ";
	printVerticalLine(root->left,line_no,hd-1);
	printVerticalLine(root->right,line_no,hd+1);
}
void VerticalOrder(Node *root)
{
	int min=0,max=0;
	findMinMax(root,&min,&max,0);
	for(int line_no = min; line_no<=max;line_no++)
	{
		printVerticalLine(root,line_no,0);
		cout<<endl;
	}
}
int main()
{
	Node *root = newNode(1);
	root->left=newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right= newNode(7);
	root->right->left->right = newNode(8);
	root->right->right->right = newNode(9);
	
	cout<<"Vertical Order traversal is\n";
	VerticalOrder(root);
	return 0;
}
