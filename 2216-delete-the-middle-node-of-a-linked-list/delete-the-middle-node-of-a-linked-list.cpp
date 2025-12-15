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
    ListNode* deleteMiddle(ListNode* head) {
        if(head== NULL|| head->next==NULL){
            return NULL;
        }
           int cnt=0;
           ListNode* temp=head;
           while(temp){
            cnt++;
            temp=temp->next;

           }
          cnt=cnt/2;
          temp=head;
          while(temp){
            cnt--;
            if(cnt==0){
            ListNode* tempo=temp->next;
            temp->next=tempo->next;
            tempo->next=NULL;
            delete tempo;
            break;
        }
        temp=temp->next;
          }
          return head;
    }
};