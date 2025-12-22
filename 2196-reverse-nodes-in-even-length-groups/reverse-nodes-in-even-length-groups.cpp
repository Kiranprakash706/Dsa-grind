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
ListNode* reverselist(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
            }
            ListNode* curr=reverselist(head->next);
            head->next->next=head;
            head->next=NULL;
            return curr;
}
ListNode* helper(ListNode* head, int level){
     if(head==NULL|| head->next==NULL){
            return head;
        }
        ListNode* temp=head;
        int cnt=1;
        while(temp->next && cnt<level){
            temp=temp->next;
            cnt++;

        }
        ListNode* curr=temp->next;
        temp->next=NULL;
        ListNode* remain=helper(curr, level+1);
        if(cnt%2==0){
            ListNode* ans=reverselist(head);
            head->next=remain;
            return ans;
        }
        else{
            temp->next=remain;
            return head;

        }
        return head;
}
    ListNode* reverseEvenLengthGroups(ListNode* head) {
       return helper(head, 1);
       
    }
};