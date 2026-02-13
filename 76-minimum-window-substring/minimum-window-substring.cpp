class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char, int > mapp;
       for(char ch:t){
        mapp[ch]++;
       }
       int min_len=INT_MAX;
       int required=mapp.size();
       int formed=0;
       unordered_map<char, int > mapp2;
       int l=0;
       int r=0;
       int start=0;
       while(r<s.length()){
        mapp2[s[r]]++;
        if(mapp.count(s[r]) && mapp[s[r]]==mapp2[s[r]]){
            formed++;
        }
        while(formed==required){
            if(r-l+1<min_len){
                min_len=r-l+1;
                start=l;
            }
            mapp2[s[l]]--;
            if(mapp2[s[l]]==0){mapp2.erase(s[l]);}
            if(mapp.count(s[l]) && mapp2[s[l]]<mapp[s[l]]){
                formed--;
            }
            l++;
        }
        r++;
       }
       return min_len==INT_MAX?"":s.substr(start,min_len);
    }
};