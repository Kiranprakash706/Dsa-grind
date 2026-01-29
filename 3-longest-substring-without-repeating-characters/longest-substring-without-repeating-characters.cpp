class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        unordered_map<char, int >mapp;
        int left=0;
       
        for(int i=0;i<s.size();i++){
           if(mapp.find(s[i])!=mapp.end() && mapp[s[i]]>=left){
            left=mapp[s[i]]+1;
           }
           mapp[s[i]]=i;
           maxlen=max(maxlen, i-left+1);
        }
        return maxlen;
    }
};