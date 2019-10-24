/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*t=NULL;
        int carry=0,sum;
        ListNode *prev,*curr,*fut;
        
        
        
        while(l1!=NULL || l2!=NULL){
            sum = carry+(l1?l1->val:0)+(l2?l2->val:0);
            
            // carry = sum/10;
            carry = (sum>=10)?1:0;
            
            //sum
            sum = sum%10;
            
            ListNode *temp = new ListNode(sum);
            
            if(head==NULL){
                head=temp;
                t=temp;
            }else{
                t->next=temp;
                t=temp;
            }
            
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry>0){
            t->next=new ListNode(carry);
        }
        return head;
    }
};
