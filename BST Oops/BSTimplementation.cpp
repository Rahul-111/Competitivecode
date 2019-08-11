#include<iostream>
#include "BinaryTreeNode.h"
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
class BST{
	BinaryTreeNode<int> *root;
	public:
		BST(){
			root=NULL;
		}
		
		~BST(){
			delete root;
		}
		
	private:
			
			BinaryTreeNode<int>* deleteHelper(int data,BinaryTreeNode<int> *node){
				if(node==NULL)
					return NULL;
				if(data>node->data){
					node->right=deleteHelper(data,node->right);	
//					return node;
				}
				else if(data < node->data){
					node->left=deleteHelper(data,node->left);
//					return node;
				}
				else if(node->data==data){
					//1 if both left and right ==NULL
					if(node->left==NULL && node->right==NULL){
						delete node;
						return NULL;
					}
					//2 left is not null
					else if(node->right==NULL && node->left!=NULL){
						BinaryTreeNode<int> *temp =node->left;
						node->left=NULL;
						delete node;
						return temp;
					}//3 right is not null
					else if(node->left==NULL && node->right!=NULL){
						BinaryTreeNode<int> *temp =node->right;
						node->right=NULL;
						delete node;
						return temp;
					}//4 both left and right present 
					else{
						BinaryTreeNode<int> *minNode = node->right;
						while(minNode->left!=NULL){
							minNode=minNode->left;
						}
						int right_min=minNode->data;
						node->data=right_min;
						node->right=deleteHelper(right_min,node->right);
//						return node;
					}
				}
				return node;
			}	
		public:	
		void deleteData(int data){
			root=deleteHelper(data,root);
		}
		private:
			
			BinaryTreeNode<int>* inserthelper(int data,BinaryTreeNode<int> *node){
				
				if(node==NULL){
					BinaryTreeNode<int> *t = new BinaryTreeNode<int>(data);
					return t;
				}
				else if(node->data < data){
					node->right=inserthelper(data,node->right);
				}
				else{
					node->left=inserthelper(data,node->left);
				}
				return node;
			}
		public:
			void insert(int data){
				root=inserthelper(data,root);
			}
		private:
			bool hasData(int data,BinaryTreeNode<int> * node){
				if(node==NULL)
					return false;
				if(node->data==data)
					return true;
				else if(data < node->data)
					return hasData(data,node->left);
				else
					return hasData(data,node->right);
			}
			
		public:
			bool hasData(int data){
				return hasData(data,root);
			}
			
			void printTree(BinaryTreeNode<int> *root){
				if(root==NULL)
					return;
				
				cout<<root->data<<":";
				if(root->left!=NULL){
					cout<<"L"<<root->left->data;
				}
				if(root->right!=NULL){
					cout<<"R"<<root->right->data;
				}
				cout<<endl;
				printTree(root->left);
				printTree(root->right);
			}
			void print(){
				printTree(root);
			}
				
		private:
				pair<Node*,Node*> BSTtoLL(BinaryTreeNode<int> *node){
					//base case
					if(node==NULL){
						pair<Node*,Node*> t;
						t.first=NULL;
						t.second=NULL;
						return t;
					}
					
					Node *temp = new Node(node->data);
					
					pair<Node*,Node*> leftTree = BSTtoLL(node->left);
					pair<Node*,Node*> rightTree=BSTtoLL(node->right);
					
					pair<Node*,Node*> pair;
					//if left half exist
					if(leftTree.first!=NULL){
						pair.first=leftTree.first;
						pair.second=leftTree.second;
						pair.second->next=temp;
						pair.second=temp; 
						if(rightTree.first==NULL){ // only left exist
							return pair;
						}
					} // if both exist
					if(leftTree.first!=NULL && rightTree.first!=NULL){
						pair.second->next=rightTree.first;
						pair.second=rightTree.second;
						return pair;
					}// if only right half exist
					if(rightTree.first!=NULL && leftTree.first==NULL){
						pair.first=temp;
						temp->next=rightTree.first;
						pair.second=rightTree.second;
						return pair;
					} //for leaf node
					else{
						pair.first=temp;
						pair.second=temp;
					}
					
					return pair;
					
				}
		public:
				Node *LL(){
					pair<Node*,Node*> ans = BSTtoLL(root);
					return ans.first;
				}		
};
int main(){
	BST b;
	b.insert(10);
	b.insert(5);
//	b.insert(20);
	b.insert(3);
	b.insert(7);
	b.insert(15);
	b.print();
	Node*head=b.LL();
	cout<<"\nLinked List is"<<endl;
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\nBST"<<endl;
	b.print();
	return 0;
}

