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
        if(head==NULL ){
            return head;
        }
        Node* temp=head;
        while(temp){
            if(temp->child!=NULL){
                Node* vall=temp->child;
                Node* temp2=temp->next;
                temp->next=vall;
                temp->next->prev=temp;
                temp->child=NULL;
                while(vall->next!=NULL){
                    vall=vall->next;
                }
                if(temp2){
                vall->next=temp2;
                temp2->prev=vall;
                }
            
            }
            temp=temp->next;
        }
        return head;
    }
};