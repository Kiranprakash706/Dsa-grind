class Solution {
public:
    bool wordPattern(string pattern, string s) {
       
        unordered_map<char, string> mapp;
        unordered_map<string, char> mapp2;
        int  i=0;
        for(int j=0;j<pattern.size();j++){
            string temp="";
            if(i==s.size()){
                return false;
            }
            while(i<s.size()){
                if(isspace(s[i])){
                    i++;
                    break;
                }
                else{
                    temp+=s[i];
                }
                i++;
            }
            if(mapp.find(pattern[j])==mapp.end() && mapp2.find(temp)==mapp2.end()){
                mapp[pattern[j]]=temp;
                mapp2[temp]=pattern[j];
            }
            else{
                if(mapp[pattern[j]]!=temp){
                    return false;
                    break;
                }
            }
        }
        if(i<s.size()-1){
            return false;
        }
        return true;
    }
};