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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* , bool>mapp;
        ListNode* temp=headA;
        while(temp){
            mapp[temp]=true;
            temp=temp->next;

        }
        ListNode* temp2=headB;
        while(temp2){
            if(mapp.find(temp2)!=mapp.end()){
                return temp2;

            }
            temp2=temp2->next;
        }
        return NULL;
    }
};