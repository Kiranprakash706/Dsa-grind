class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>ans;
        int count=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                ans.push_back(count);
                count=1;
            }
        }
        ans.push_back(count);
        int sum=0;
        for(int i=0;i<ans.size()-1;i++){
            sum=sum+min(ans[i], ans[i+1]);
        }
        return sum;
    }
};