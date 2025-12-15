class Node{
    public:
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int key, int value){
        this->key=key;
        this->value=value;
        next=prev=NULL;
    }
};
class LRUCache {
public:
unordered_map<int , Node*>mapp;
int cap;
Node*head;
Node* tail;

void addnode(Node* node){
    node->next=head->next;
    node->prev=head;
    node->next->prev=node;
    head->next=node;

}
void deletenode(Node* node){
   Node* temp=node->prev;
   temp->next=node->next;
   node->prev=NULL;
   node->next->prev=temp;

}
    LRUCache(int capacity) {
        cap=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1, -1);
        head->next=tail;
        tail->prev=head;

    }
    
    int get(int key) {
        if(mapp.find(key)==mapp.end()){
            return -1;
        }
        Node* node=mapp[key];
        deletenode(node);
        addnode(node);
        return node->value;
        
    }
    
    void put(int key, int value) {
       if(mapp.find(key)!=mapp.end()){
            Node* node=mapp[key];
            node->value=value;
            deletenode(node);
            addnode(node);
       }
       else{
        if(mapp.size()==cap){
            Node* lru=tail->prev;
            mapp.erase(lru->key);
            deletenode(lru);
            delete(lru);
        }
        Node* node=new Node(key, value);
        mapp[key]=node;
        addnode(node);
       } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */