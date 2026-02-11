class Solution {
public:
bool isVowel(char c) {
    c = tolower(c);   // handles uppercase too
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
    int maxVowels(string s, int k) {
        int ind=0;
        if(k>s.length()){
            return 0;
        }
        int cnt=0;
        int maxcnt=0;
        for(ind=0;ind<k;ind++){
            if(isVowel(s[ind])){
                cnt++;
            }
        }
        maxcnt=max(cnt, maxcnt);
        for(int i=ind;i<s.length();i++){
            if(isVowel(s[i])){
                cnt++;
            }
            if(isVowel(s[i-k])){
                cnt--;
            }
            maxcnt=max(maxcnt , cnt);

        }
        return maxcnt;
    }
};