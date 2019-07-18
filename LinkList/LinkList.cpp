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
Node *takeInput(){
	int data;
	cin>>data;
	Node *head = NULL;
	while(data!=-1){
		Node *newNode = new Node(data);
		if(head==NULL){
			head=newNode;
		}
		else{
			Node *temp = head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
		}
		cin>>data;
	}
	return head;
}
vector<Node *> ReverseHeadTail(Node* head,Node* t){
//	cout<<head->data<<" "<<t->data;
	if(head==NULL){
		
		vector<Node *> x;
		x.push_back(NULL);
		return x;
	}
	Node *prev,*curr,*fut;
	prev=NULL;
	curr=head;
	t=curr;
	fut=head->next;
	
	while(curr->next!=NULL){
		curr->next=prev;
		prev=curr;
		curr=fut;
		fut=fut->next;
	}
	curr->next=prev;
	head=curr;
	cout<<endl;
//	printList(curr);
	
	vector<Node *> v;
	v.push_back(head);
	v.push_back(t);
	
	return v;
}
Node * KReverse(Node *head,int k){
	Node *curr,*prev,*fut;
	curr=head;
	prev=NULL;
	fut=NULL;
	int count=0;
	while(curr!=NULL && count<k){
		fut = curr->next;
		curr->next=prev;
		prev=curr;
		curr=fut;
		count++;
	}
	
	if(fut!=NULL){
		head->next=KReverse(fut,k);
	}
	return prev;
}
int main(){
	//statically
//	Node n1(1);
//	Node n2(2);
//	Node *head=&n1;
//	Node n3(3);
//	Node n4(4);
//	Node n5(5);
//	
//	n1.next=&n2;
//	n2.next=&n3;
//	n3.next=&n4;
//	n4.next=&n5;
	Node *head=takeInput();
	cout<<"\n Link list is "<<endl;	
	printList(head);
//	Node *t=head;
//		while(t->next!=NULL){
////			cout<<t->data<<" ";
//			t=t->next;
//		}	
//	vector<Node * > d=ReverseHeadTail(head,t);
//	cout<<"\n From reverse link list "<<endl;
//	printList(d[0]);
//Dynamically
//	Node *n3 = new Node(10);
//	Node *head = n3;
//	
//	Node *n4 = new Node(20);
//	n3->next=n4;
	int k=3;
	cout<<"\n After "<<3<<" sorted "<<endl;
	Node *h=KReverse(head,k);
	printList(h);	
	return 0;
}
