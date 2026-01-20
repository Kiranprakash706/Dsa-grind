class Solution {
public:
bool ispalindrome(string s,int ini, int fi){
    int start=ini;
    int end=fi;
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
            break;
        }
        start++;
        end--;
    }
    return true;
}
void helper(int index, string s,vector<vector<string>>&res, vector<string>& path){
    if(index==s.length()){
        res.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(ispalindrome(s,index, i)){
            path.push_back(s.substr(index, i-index+1));
            helper(i+1,s,res,path);
            path.pop_back();
        }
    }

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        helper(0, s, res, temp);
        return res;
    }
};