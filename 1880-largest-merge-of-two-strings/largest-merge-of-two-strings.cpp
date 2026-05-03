
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        string res = "";
        while(i < word1.length() && j < word2.length()) {
            
         if(word1.substr(i)<word2.substr(j)){
            res+=word2[j];
            j++;
         }
         else{
            res+=word1[i];
            i++;
         }
        }
        
        res+=word1.substr(i);
        res+=word2.substr(j);
        return res;
    }
};