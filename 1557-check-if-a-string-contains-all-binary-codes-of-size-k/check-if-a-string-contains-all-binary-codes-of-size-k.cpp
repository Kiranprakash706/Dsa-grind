class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()){
            return false;
        }
        int val=pow(2,k);
        unordered_map<string,int > mapp;

        for(int i=0;i<s.size()-k+1;i++){
            string temp=s.substr(i,k);
            mapp[temp]++;
        }
        if(mapp.size()==val){
            return true;
        }
        return false;
    }
};