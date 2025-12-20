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
    int pairSum(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        if(head->next==NULL){
            return head->val*2;
        }
        unordered_map<int , ListNode*>mapp;
        int maxval=INT_MIN;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            mapp[cnt]=temp;
             cnt++;
            temp=temp->next;
        }
        temp=head;
        int a=0;
        int sum=0;
        while(a<=(cnt/2)-1 && temp){
            sum=temp->val;
            int twin=cnt-1-a;
            ListNode* node=mapp[twin];
            sum+=node->val;
            maxval=max(maxval, sum);
            temp=temp->next;
            a++;
        }
        return maxval;
       
    }
};