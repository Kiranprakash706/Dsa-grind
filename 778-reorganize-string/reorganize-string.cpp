class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char , int >mapp;
        int n=s.length();
        for(int i=0;i<s.length();i++){
            mapp[s[i]]++;
            if(mapp[s[i]]>(n+1)/2){
                return "";
            }
        }
        priority_queue<pair<int , char >>pq;
        for(auto &i:mapp){
            pq.push({i.second, i.first});
        }
        string temp="";
       pair<int, char> prev={0,'#'};
        while(!pq.empty()){
                pair<int , char>curr=pq.top();
                pq.pop();
                temp+=curr.second;
                if(prev.first>0){
                    pq.push({prev.first, prev.second});
                }
                curr.first--;
                prev={curr.first, curr.second};

                }
        
        return temp;
    }
};