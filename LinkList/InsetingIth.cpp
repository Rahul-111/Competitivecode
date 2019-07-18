#include<bits/stdc++.h>
#include "Node.h"
using namespace std;
void printList(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node *takeInput_better(){
	int data;
	cin>>data;
	Node *head=NULL;
	Node *tail=NULL;
	while(data!=-1){
		Node *newNode = new Node(data);
		if(head==NULL){
			head=newNode;
			tail=newNode;
		}
		else{
			tail->next=newNode;
			tail=tail->next;
			// tail=newNode;
		}
		cin>>data;
	}
	return head;
}
Node * InsertAtK(Node *head,int k,int data){
	if(head==NULL)
		return NULL;
	
	if(k==1){
		Node *temp = new Node(data);
		temp->next=head;
		head=temp;
//		cout<<"Done"<<temp->data;
		return head;
	}
	if(k==2){
		Node *temp = new Node(data);
		temp->next=head->next;
		head->next=temp;
		return head;
	}
	head->next= InsertAtK(head->next,--k,data);
}
int main(){
	Node *head=takeInput_better();
	cout<<"\n Link list is "<<endl;	
	printList(head);
	cout<<endl;
	Node *h=InsertAtK(head,7,99);
	cout<<"\n Link list is "<<endl;	
	printList(h);
	return 0;
}
