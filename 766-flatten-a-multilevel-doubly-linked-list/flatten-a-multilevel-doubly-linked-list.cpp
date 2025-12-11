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
        // stack<Node*>st;
       while(temp!=NULL){
        if(temp->child!=NULL){
            Node* vall=temp->child;
            Node* temp2=temp->next;
            temp->next=temp->child;
            temp->child->prev=temp;
            while(vall->next!=NULL){
                vall=vall->next;
            }
            vall->next=temp2;
            if(temp2){
                temp2->prev=vall;
               
            }
             temp->child=NULL;
           
            
        }
         temp=temp->next;
       

       }
    
       return head;

    }
};