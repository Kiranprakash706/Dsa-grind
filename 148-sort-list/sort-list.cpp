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
ListNode* merge(ListNode* lefti, ListNode* righti){
    ListNode* tempo=new ListNode(-1);
    ListNode* head=tempo;
    while(lefti && righti){
        if(lefti->val>=righti->val){
            head->next=righti;
            righti=righti->next;
            head=head->next;

        }
        else{
                head->next=lefti;
                lefti=lefti->next;
                head=head->next;


        }

    }
    while(lefti){
        head->next=lefti;
        lefti=lefti->next;
        head=head->next;
    }
    while(righti){
        head->next=righti;
        righti=righti->next;
        head=head->next;
    }
    return tempo->next;
}
ListNode* findmiddle(ListNode* head){
   ListNode* slow=head;
   ListNode* fast=head;
   while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
   }
   return slow;

}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle=findmiddle(head);
        ListNode* temp=middle->next;
         middle->next=NULL;
        ListNode* leftii=sortList(head);
        ListNode* righti=sortList(temp);
        return merge(leftii , righti);
        
    }
};