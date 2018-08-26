// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
#include<stdlib.h>
using namespace std;
vector<int> V[6];
// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};
 
// A utility function to create a new node
struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
void getVerticalOrder(Node* root, int hd)
{
    // Base case
    if (root == NULL)
        return;
 
    // Store current node in map 'm'
    V[hd+2].push_back(root->key);
 
    // Store nodes in left subtree
    getVerticalOrder(root->left, hd-1);
 
    // Store nodes in right subtree
    getVerticalOrder(root->right, hd+1);
}
 
// The main function to print vertical oder of a binary tree
// with given root
void printVerticalOrder(Node* root)
{
    // Create a map and store vertical oder in map using
    // function getVerticalOrder()
    //vector<int >  m[10]; //m
    int hd = 0;
	
    
    getVerticalOrder(root, hd);
 	
    // Traverse the map and print nodes at every horigontal
    // distance (hd)
    
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < V[i].size(); j++) {
			cout<<V[i][j]<<"   ";
		}
		cout<<endl;
	}
}
 
// Driver program to test above functions
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
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}

