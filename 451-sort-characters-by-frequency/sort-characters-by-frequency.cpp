class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mapp;
        for(int i=0;i<s.length();i++){
            mapp[s[i]]++;
        }
        priority_queue<pair<int, char>>pq;
        for(auto &i:mapp){
            pq.push({i.second, i.first});
        }
        string ans="";
        while(!pq.empty()){
            int freq=pq.top().first;
            char temp=pq.top().second;
            pq.pop();
            while(freq--){
                ans+=temp;
            }
        }
        return ans;
    }
};