/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* mergelist(ListNode *l1, ListNode *l2)
    {
       if(l1==NULL){
           return l2;
       }
       if(l2==NULL){
           return l1;
       }
       ListNode* ans=new ListNode(0);
       ListNode* temp=ans;

       while(l1!=NULL && l2!=NULL){
           if(l1->val<l2->val){
             temp->next=l1;
             temp=l1;
             l1=l1->next;
           }
           else
           {
               temp->next=l2;
               temp=l2;
               l2=l2->next;
           }
       }
       while(l1!=NULL){
           temp->next=l1;
             temp=l1;
             l1=l1->next;
       }
       while(l2!=NULL){
           temp->next=l2;
               temp=l2;
               l2=l2->next;
       }
       ans=ans->next;
       return ans;

    }
    ListNode* findmid(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=findmid(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=mergesort(left);
        right=mergesort(right);
        // merge the list
        ListNode* result=mergelist(left,right);
        return result;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        return mergesort( head);
    }
};