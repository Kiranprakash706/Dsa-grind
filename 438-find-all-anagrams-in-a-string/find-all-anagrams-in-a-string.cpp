class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int > ans;
      unordered_map<char, int > mappS;
      unordered_map<char, int >mappP;
      for(int i=0;i<p.size();i++){
        mappP[p[i]]++;
      }
      for(int i=0;i<p.size();i++){
        mappS[s[i]]++;
      }
      if(mappS==mappP){
        ans.push_back(0);
      }
      for(int i=p.size();i<s.size();i++){
        mappS[s[i]]++;
        mappS[s[i-p.size()]]--;
        if(mappS[s[i-p.size()]]==0){
            mappS.erase(s[i-p.size()]);
        }
        if(mappS==mappP){
            ans.push_back(i-p.size()+1);
        }
      }
      return ans;
    }
};