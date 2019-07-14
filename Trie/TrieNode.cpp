#include<bits/stdc++.h>
#include"Trie.h"
using namespace std;
class TrieNode{
	public:
		char data;
		TreeNode **children;
		bool isTerminal;
		
	    TrieNode(char data){
	    	this->data=data;
	    	children = new TrieNode*[26]; //assuming lower case alphabets
	    	for(int i=0;i<26;i++){
	    		children[i]=NULL;
			}
			isTerminal=false;
		}
};

int main(){
	Trie t1,t2;
	t1.insert("ans");
	t1.insert("another");
	t1.insert("this");
	t1.insert("the");
	
	if(t1.search("the"))
		cout<<"Yes, Present";
	else
		cout<<"OOps,NO";
		
	return 0;
}
