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
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*> , compare>pq;
        for(auto &i:lists){
            if(i){
                pq.push(i);
            }
        }
        ListNode* temp=new ListNode(-1);
        ListNode* head=temp;
        while(!pq.empty()){
            ListNode* temp2=pq.top();
            pq.pop();
            temp->next=temp2;
            if(temp2->next){
                pq.push(temp2->next);
            }
            temp=temp->next;
          }

          return head->next;
    }
};