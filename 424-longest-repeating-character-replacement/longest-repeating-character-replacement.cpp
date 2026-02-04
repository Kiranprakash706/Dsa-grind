class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxfreq=0;
       int maxlen=0;
       int l=0;
       int r=0;
        unordered_map<char, int > mapp;

      while(r<s.length()){
            mapp[s[r]]++;
            maxfreq=max(maxfreq,mapp[s[r]]);
            while((r-l+1)-maxfreq>k){
                mapp[s[l]]--;
                if(mapp[s[l]]==0){
                    mapp.erase(s[l]);

                }
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen, r-l+1);
            }
            r++;
      }
      return maxlen;
    }
};