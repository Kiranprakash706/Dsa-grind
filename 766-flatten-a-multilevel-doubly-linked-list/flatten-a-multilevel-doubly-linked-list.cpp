/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        stack<Node*>st;
        Node* tempo=NULL;

        Node* temp=head;
        while(temp){
            if(temp->child!=NULL){
                if(temp->next){
                    st.push(temp->next);
                }
                // temp->next->prev=NULL;
                temp->next=temp->child;
                temp->next->prev=temp;
                temp->child=NULL;
            }
            tempo=temp;
            temp=temp->next;
        }
        temp=tempo;
        while(!st.empty()){
           tempo=st.top();
           st.pop();
           temp->next=tempo;
           tempo->prev=temp;
           temp=temp->next;
           while(temp->next!=NULL){
            temp=temp->next;
           }

        }
        return head;
    }
};