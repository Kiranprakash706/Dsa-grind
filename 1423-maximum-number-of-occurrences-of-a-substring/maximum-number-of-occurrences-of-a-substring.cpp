class Solution {
public:
    int maxFreq(string s, int maxLetters, int minsize, int maxsize) {
        int l=0;
        int r=0;
        int maxocc=0;
        unordered_map<char, int> mapp;
        unordered_map<string ,int> mapp2;

        while(r<s.length()){
            mapp[s[r]]++;
            while(mapp.size()>maxLetters || r-l+1 >minsize){
                mapp[s[l]]--;
                if(mapp[s[l]]==0){
                    mapp.erase(s[l]);
                }
                l++;
            }
            if(mapp.size()<=maxLetters && (r-l+1)==minsize ){
                string temp=s.substr(l, r-l+1);
                mapp2[temp]++;
                maxocc=max(maxocc,mapp2[temp]);
            }
            r++;
        }
        return maxocc;
    }
};