class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=-1;
        for(int j=0;j<word.length();j++){
            if(word[j]==ch){
                i=j;
                break;
            }
        }
        reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};