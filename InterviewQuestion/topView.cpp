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
void printVerticalOrder(Node *root){
	map<int,vector<int>> Map;
	int h=0;
	queue<pair<Node*, int> > Q; 
    Q.push(make_pair(root, h));
	
	while(!Q.empty()){
		pair<Node*,int> temp=Q.front();
		Node* t=temp.first;
		h=temp.second;
		Q.pop();
		Map[h].push_back(t->data);
		
		if(t->left!=NULL)
			Q.push(make_pair(t->left,h-1));
		if(t->right!=NULL)
			Q.push(make_pair(t->right,h+1));
	} 
	
	cout<<"hello"<<endl;
	map<int,vector<int> >::iterator it; 
    for (it=Map.begin(); it!=Map.end(); it++) 
    { 
//        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[0] << " "; 
//        cout << endl; 
    } 
    cout<<"endl";
}
int main() 
{ 
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
//    cout<<"Level Order traversal"<<endl;
//    levelOrder(root);
	cout << "Vertical order traversal is \n"; 
    printVerticalOrder(root); 
    return 0; 
} 
