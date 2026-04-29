class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans="";
        string temp="";
        for(int i=0;i<s.length();i++){
            if(i!=0 && s[i]==' '){
                ans=temp+' '+ans;
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        ans=temp+' '+ans;
        ans.pop_back();
        return ans;
    }
};