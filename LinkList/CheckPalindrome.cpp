#include<bits/stdc++.h>
#include "Node.h"
using namespace std;
Node *reverse(Node *head){
    Node *prev,*curr,*fut;
    prev=NULL;
    curr=head;
    fut=NULL;
    while(curr!=NULL){
        fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
    }
    return prev;
}
void printList(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node* addTwoLists(Node* h1, Node* h2) {
    // Code here
	Node *sum=NULL;
    
    int carry=0,num,total;
    while(h1!=NULL && h2!=NULL){
        num=(h1->data+h2->data+carry)%10;
        cout<<num<<" ";
        Node *t = new Node(num);
        if(sum==NULL){
            sum=t;
        }else{
            t->next=sum;
            sum=t;
        }
        carry=(h1->data+h2->data+carry)/10;
        h1=h1->next;
        h2=h2->next;
    }
    while(h1!=NULL){
        num=(h1->data+carry)%10;
        cout<<num<<" ";
        Node *t = new Node(num);
        if(sum==NULL){
            sum=t;
        }else{
            t->next=sum;
            sum=t;
        }
        carry=(carry+h1->data)/10;
        h1=h1->next;
    }
	while(h2!=NULL){
        num=(h2->data+carry)%10;
        cout<<num<<" ";
        Node *t = new Node(num);
        if(sum==NULL){
            sum=t;
        }else{
            t->next=sum;
            sum=t;
        }
        carry=(carry+h2->data)/10;
        h2=h2->next;
    }
    return sum;
}
Node *middle(Node *head){
    Node *slow,*fast;
    slow=fast=head;
    Node *back=NULL;
    while(fast!=NULL && fast->next!=NULL){
        back=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=NULL)
        slow=slow->next;
    return slow;
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
bool isPalindrome(Node *head)
{ 
    Node *h=head;
    Node *x =middle(h);
    x=reverse(x);
    while(x!=NULL){
        if(x->data!=head->data){
            return false;
        }
        head=head->next;
        x=x->next;
    }
    return true;
}
int main(){
	Node *h1=takeInput_better();
	Node *mid=middle(h1);
	cout<<"middle"<<mid->data<<endl;
//	if(isPalindrome(h1))
//		cout<<"1"<<endl;
//	else
//		cout<<"0"<<endl;
	return 0;
}
