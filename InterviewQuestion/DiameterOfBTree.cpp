#include<bits/stdc++.h>
using namespace std;
struct Node
{	int data;
	struct Node *left,*right;
};
Node * newNode(int data)
{
	Node *temp = new Node;
	temp->data=data;
	temp->right=temp->left=NULL;
	return temp;
}
void levelOrder(Node *root){
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		int nodesInlevel=Q.size();
		while(nodesInlevel>0){
			Node *t=Q.front();
			cout<<t->data<<" ";	
			Q.pop();
			if(t->left!=NULL){ 
				Q.push(t->left);
			}
			if(t->right!=NULL){
				Q.push(t->right);
			}
			nodesInlevel--;	
		}
		cout<<endl;
	}
}
int height(Node *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
int Diameter(Node *root){
	//time complexity O(n*n)
	if(root==NULL)
		return 0;
	int h=height(root->left)+height(root->right);
	int lr1=Diameter(root->left);
	int lr2=Diameter(root->right);
	return max(h,max(lr1,lr2));
}
pair<int,int> heightDiameter(Node *root){
	if(root==NULL){
		pair<int,int> p;
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int> leftAns=heightDiameter(root->left);
	pair<int,int> rightAns=heightDiameter(root->right);
	int ld=leftAns.second;
	int lh=leftAns.first;
	int rd=rightAns.second;
	int rh=rightAns.first;
	
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;
}
int main(){ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    root->right->right->left= newNode(10); 
    root->right->right->left->right= newNode(11); 
    root->right->right->left->right->right= newNode(12); 
    cout<<"Level Order traversal"<<endl;
    levelOrder(root);
    cout<<"Diameter of a tree = "<< Diameter(root);
    pair<int,int> ans=heightDiameter(root);
    cout<<"\n Diameter of a tree = "<<ans.second;
//	cout << "Vertical order traversal is \n"; 
//    printVerticalOrder(root); 
    return 0; 
}
