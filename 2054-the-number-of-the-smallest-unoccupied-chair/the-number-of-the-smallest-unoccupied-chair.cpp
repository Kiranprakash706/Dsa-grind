class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
         vector<pair<pair<int , int>, int>>v;
        for(int i=0;i<times.size();i++){
            v.push_back({{times[i][0],times[i][1]},i});
        }
        priority_queue<pair<int , int > , vector<pair<int , int >>, greater<pair<int , int >>>pq;
        priority_queue<int , vector<int>, greater<int>>chairoccupied;
         
        sort(v.begin(), v.end());
        int chair=0;

        for(int i=0;i<v.size();i++){
            int arrival=v[i].first.first;
            int depp=v[i].first.second;
            int idx=v[i].second;
            while(!pq.empty() && pq.top().first<=arrival){
                chairoccupied.push(pq.top().second);
                pq.pop();
            }
            int chaircurr;
            if(chairoccupied.empty()){
                chaircurr=chair;
                chair++;
            }
            else{
                 chaircurr = chairoccupied.top();
                    chairoccupied.pop();
            }
            if(idx==targetFriend){
                return chaircurr;
            }
            pq.push({depp,chaircurr});

        }
        return -1;
    }
};