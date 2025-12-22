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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* dummy1=new ListNode(-1);
        ListNode* ans=dummy1;
        ListNode* dummy2=new ListNode(-1);
        ListNode* ans2=dummy2;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                dummy1->next=temp;
                dummy1=temp;
                temp=temp->next;
                dummy1->next=NULL;

            }
            else{
                dummy2->next=temp;
                dummy2=temp;
                temp=temp->next;
                dummy2->next=NULL;
            }
        }
        dummy1->next=ans2->next;
        ans2=NULL;
        return ans->next;
    }
};