class Solution {
public:

    string removeStars(string s) {
        int i=0;
        int n=s.size();
        string res="";
        while(i<n){
            if(s[i]!='*'){
                res+=s[i];
                i++;
            }
            else if(s[i]=='*'){
                
                
                while(s[i]=='*' &&i<n){
                    if(!res.empty())res.pop_back();
                    i++;
                }
            }
            else{
                i++;
            }
            
            if(i>=n){
                break;
            }
        }
        return res;
    }
};