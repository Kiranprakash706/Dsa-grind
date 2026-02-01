class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mapp;
        int left=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            if(mapp.count(s[i]) && mapp[s[i]]>=left){
                left=mapp[s[i]]+1;
            }
            mapp[s[i]]=i;
            maxlen=max(maxlen, i-left+1);
        }
        return maxlen;
    }
};