class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>timeline(1001, 0);
        for(int i=0;i<trips.size();i++){
            int from=trips[i][1];
            int to=trips[i][2];
            timeline[from]+=trips[i][0];
            timeline[to]-=trips[i][0];
        }
        int curr=0;
        for(int i:timeline){
            curr+=i;
            if(curr>capacity){
                return false;
            }
        }
        return true;
    }
};


//Heap method
/*class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int , int>, vector<pair<int, int >>, greater<pair<int , int >>>pq;
        sort(trips.begin(), trips.end(), [](vector<int>&a, vector<int>&b){
            return a[1]<b[1];
        });
        for(int i=0;i<trips.size();i++){
            while(!pq.empty() && pq.top().first<=trips[i][1]){
                capacity+=pq.top().second;
                pq.pop();

            }
            if(capacity>=trips[i][0]){
                pq.push({trips[i][2], trips[i][0]});
                capacity-=trips[i][0];
            }
            else{
                return false;
            }
        }
        return true;
    }
};*/