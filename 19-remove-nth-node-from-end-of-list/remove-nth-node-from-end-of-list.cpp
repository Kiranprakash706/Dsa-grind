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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL ){
            return NULL;
        }
        if(head->next==NULL && n==1){
            return NULL;
        }
        int k=0;
        ListNode* temp=head;
        while(temp){
            k++;
            temp=temp->next;
        }
        int cnt=k-n;
        temp=head;
        k=0;
        if(cnt==0){
            ListNode* tempo=temp;
            head=head->next;
            temp->next=tempo->next=NULL;
        }
        else{

        
        while(temp){
            if(k==cnt-1){
                ListNode* tempo=temp->next;
                temp->next=temp->next->next;
                tempo->next=NULL;
                break;

            }
            temp=temp->next;
            k++;
            
        }
        }
        return head;

    }
};