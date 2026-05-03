class Solution {
public:
    vector<int> diStringMatch(string s) {
        int i=0;
        vector<int>v;
        int j=s.length();
        for(char ch:s){
            if(ch=='I'){
                v.push_back(i++);

            }
            else{
                v.push_back(j--);
            }
        }
        v.push_back(i);
        return v;
    }
};