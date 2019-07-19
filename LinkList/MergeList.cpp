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
Node *MergeList(Node *h1,Node *h2){
	Node *head,*tail;
	head=tail=NULL;
	if(h1->data>h2->data){
		head=tail=h2;
		h2=h2->next;
	}
	else{
		head=tail=h1;
		h1=h1->next;
	}
	while(h1->next!=NULL && h2->next!=NULL){
		if(h1->data > h2->data){
			tail->next=h2;
			tail=h2;
			h2=h2->next;
		}
		else if(h1->data<h2->data){
			tail->next=h1;
			tail=h1;
			h1=h1->next;
		}
	}
	if(h1->next!=NULL){
		tail->next=h1;
	}
	else if(h2->next!=NULL){
		tail->next=h2;
	}
	return head;
}
void Middle(Node *head){
	Node *slow,*fast;
	slow=head;
	fast=head;
//	while(fast->next!=NULL){
//		slow=slow->next;
//		fast=fast->next->next;
//	}
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}	   
	cout<<slow->data<<endl;
}
int main(){
	Node *head1=takeInput_better();
//	Node *head2=takeInput_better();
//	Node *h=MergeList(head1,head2);
//	printList(head1);
	cout<<"\n Median of above linklist is"<<endl;
	Middle(head1);
	return 0;
}
