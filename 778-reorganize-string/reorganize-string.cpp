class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int , char>>pq;
        int n=s.length();
       unordered_map<char, int >mapp;
       for(int i=0;i<s.length();i++){
        mapp[s[i]]++;
        if(mapp[s[i]]>((n+1)/2)){
            return "";
        }
       }
       for(auto &i:mapp){
        pq.push({i.second, i.first});
       }
        string temp="";
        pair<int, char> prev={0,'#'};
        while(!pq.empty()){
            pair<int , char>recc=pq.top();
            temp+=recc.second;
            pq.pop();
            if(prev.first>0){
                pq.push({prev.first, prev.second});
            }
           recc.first--;
            prev={recc.first, recc.second};
        }
        return temp;
       

    }
};