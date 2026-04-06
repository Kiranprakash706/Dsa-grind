class MKAverage {
public:
deque<int>q;
int m;
int k;
multiset<int>low,mid,high;
long long  totalsum;
    MKAverage(int m, int k) {
        this->m=m;
        this->k=k;
        totalsum=0;
    }
    
   void  balance(){
     while(low.size()>k){
            auto it=prev(low.end());
            int ele=*it;
            low.erase(it);
            mid.insert(ele);
             totalsum+=ele;
        }
         while(high.size()>k){
         auto it = high.begin();   // smallest in high
        int ele = *it;
        high.erase(it);
        mid.insert(ele);
        totalsum += ele;
}
        while(low.size()<k && !mid.empty()){
            auto it=mid.begin();
            int ele=*it;
            mid.erase(it);
            low.insert(ele);
            totalsum-=ele;
        }
       
       
        while(high.size()<k && !mid.empty()){
            auto it=prev(mid.end());
            int ele=*it;
            high.insert(ele);
            mid.erase(it);
             totalsum-=ele;
        }
       

    }
    void addElement(int num) {
       q.push_back(num);
       if(!low.empty() && num<=*low.rbegin()){
        low.insert(num);
       }
       else if(!high.empty() && num>=*high.begin()){
        high.insert(num);
       }
       else{
        mid.insert(num);
        totalsum+=num;
       }
       balance();

       if(q.size()>m){
        int old=q.front();
        q.pop_front();
        if(low.find(old)!=low.end()){
           low.erase(low.find(old));
        }
        else if(high.find(old)!=high.end()){
           high.erase(high.find(old));
        }
        else{
            mid.erase(mid.find(old));
                totalsum -= old;
        }
        balance();
       }

    }
    
    int calculateMKAverage() {
        if(mid.size()<m-2*k){
            return -1;
        }
        return (long long )totalsum/mid.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */