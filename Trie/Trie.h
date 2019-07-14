#include<bits/stdc++.h>
using namespace std;
class Trie{
	TrieNode *root;
	public:
		Trie(){
			root = new TrieNode('\0');
		}
		
		void insertWord(TrieNode *root,string word){
			//base case
			if(word.size()==0){
				root->isTerminal=true;
				return;
			}
			
			int index = word[0]-'a';
			TrieNode *child;
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				child = new TrieNode(word[0]);
				root->children[index]=child;
			}
			
			//recursive call
			insertWord(child,word.substr(1));
		}
		
		//for user
		void insert(string word){
			insertWord(root,word);
		}
		
		//for search
		bool searchHelp(TrieNode *root,string word){
			//base case
			if(word.size()==0){
				if(root->isTerminal==false)
					return false;
				else
					return true;
			}
			int index = word[0]-'a';
			TrieNode *child;
			if(root->children[index]==NULL){
				return false;
			}
			if(root->children[index]!=NULL){
				child=root->children[index];
				return searchHelp(root,word.substr(1));
			}
		}
		
		bool search(string word){
			return searchHelp(root,word);
		}
		
		//for remove
		void removeWord(TrieNode *root,string word){
			//Base case
			if(word.size()==0){
				root->isTerminal=false;
				return;
			}
			//small calculations
			TrieNode *child;
			int index=word[0]-'a';
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else{
				//word not found
				return;
			}
			removeWord(child,word.substr(1));
		}
		
		void remove(word){
			removeWord(root,word);
		}
};
