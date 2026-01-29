class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()){
            return false;
        }
        set<char>st1, st2;
        vector<int>freq1(26,0), freq2(26,0);
        for(char ch:word1){
            freq1[ch-'a']++;
            st1.insert(ch);
        }
         for(char ch:word2){
           freq2[ch-'a']++;
            st2.insert(ch);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return (freq1==freq2) && (st1==st2);

    }
};