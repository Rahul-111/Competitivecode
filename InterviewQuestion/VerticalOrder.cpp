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
map<int,vector<int>> Map;
//vector<vector<int>>Map;
void verticalOrder(Node* root ,int v){
	if(root==NULL){
		return ;
	}
//	cout<<root->data<<" "<<v<<endl;
	Map[v].push_back(root->data);
	verticalOrder(root->left,v-1);
	verticalOrder(root->right,v+1);
}
int main()
{
	Node *root = newNode(1);
	root->left=newNode(2);
	root->right = newNode(3);
//	root->left->left = newNode(4);
	root->left->right = newNode(4);
//	root->right->left= newNode(6);
	root->left->right->right= newNode(5);
//	root->right->right= newNode(7);
	root->left->right->right->right=newNode(6);
	cout<<"Levelorder traversal :\n";levelOrder(root);
	int var=0;
	cout<<"Vertical Order traversal:\n";verticalOrder(root,var);
 	for(map<int, vector<int> >::iterator ii=Map.begin(); ii!=Map.end(); ++ii){
       cout << (*ii).first << ": ";
       vector <int > inVect = (*ii).second;
       for (unsigned j=0; j<inVect.size(); j++){
           cout << inVect[j] << " ";
       }
       cout << endl;
   }
	return 0;
}
