#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include <cstdlib>
using namespace std;
int Hash[100];
struct Node{
	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
	Node *temp=new Node;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
void levelOrder(Node *root)
{
	if(root==NULL)
		return ;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp=q.front();
		cout<<temp->data<<"  ";
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}
void findMinMax(Node *root,int *min,int *max,int hd)
{
	if(root==NULL)
		return ;
	if(hd<*min)  *min=hd;
	if(hd>*max)  *max=hd;
	
	findMinMax(root->left,min,max,hd-1);
	findMinMax(root->left,min,max,hd+1);
}
void verticalSum(Node *root,int hd,int min)
{	
	
	if(root==NULL)
		return;
	verticalSum(root->left,hd-1,min);
	Hash[hd+abs(min)]+=root->data;
	verticalSum(root->right,hd+1,min);
}
int main()
{
	Node *root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"\n Levelorder traveersal  of tree\n";
	cout << "\n Vertical order sum ";
	int min=0,hd=0,max=0;
	findMinMax(root,&min,&max,0);
	verticalSum(root,hd,min);
	cout<<endl;
	for(int i=abs(min)-2;i<=max+abs(min);i++)
		cout<<Hash[i]<<"  ";
	return 0;
}
