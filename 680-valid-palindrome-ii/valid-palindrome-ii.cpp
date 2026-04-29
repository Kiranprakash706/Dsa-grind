class Solution {
public:
bool ischeck(string temp, int i, int j){
    while(i<=j){
        if(temp[i]!=temp[j]){
            return false;
        }
        i++;
        j--;

    }
    return true;
}
    bool validPalindrome(string s) {
       int i=0;
       int cnt=0;
       int j=s.length()-1;
       while(i<=j){
       if(s[i]!=s[j]){
        bool ans1=ischeck(s,i+1, j);
        bool ans2=ischeck(s,i, j-1);
        return ans1||ans2;
       }
       i++;
       j--;
       }
       return true;
    }
};