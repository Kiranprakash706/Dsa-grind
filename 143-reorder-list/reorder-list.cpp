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
ListNode* findmiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}
ListNode* reverselsit(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* curr=reverselsit(head->next);
    head->next->next=head;
    head->next=NULL;
    return curr;
}


    void reorderList(ListNode* head) {
       ListNode* temp2=head;
         ListNode* middle=findmiddle(temp2);
       ListNode* ans=reverselsit(middle->next);
       middle->next=NULL;
       while(temp2 && ans){
        ListNode* child1=temp2->next;
        ListNode* child2=ans->next;
        ans->next=temp2->next;

        temp2->next=ans;
        ans=child2;
        temp2=child1;
       }
         


    }
};