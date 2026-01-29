class MyHashMap {
    vector<pair<int , int >>mapp;
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        for(auto &i:mapp){
            if(i.first==key){
                i.second=value;
                return;
            }
        }
        mapp.push_back({key, value});
    }
    
    int get(int key) {
        for(auto &i:mapp){
            if(i.first==key){
                return i.second;
            }
        }
        return -1;
        
    }
    
    void remove(int key) {
        for(int i=0;i<mapp.size();i++){
            if(mapp[i].first==key){
                mapp.erase(mapp.begin()+i);
            }
        }
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */