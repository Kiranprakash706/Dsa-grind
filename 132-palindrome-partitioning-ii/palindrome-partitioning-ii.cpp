class Solution {
public:
vector<int>dp;

bool ispalindrome(int start, int end, string &s){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int  helper(int index, string  &s, int cut){
    if(index==s.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int mincuts=INT_MAX;
    for(int i=index;i<s.size();i++){
        if(ispalindrome(index, i, s)){
           mincuts=min(mincuts, 1+helper(i+1,s,cut+1));
        }
    }
    return dp[index]=mincuts;
}
    int minCut(string s) {
        dp.assign(s.size(), -1);
        return helper(0,s,0)-1;
        
    }
};