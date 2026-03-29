class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>temp(n,0);
        for(int i=0;i<words.size();i++){
            for(char ch:words[i]){
                temp[i] |=(1<<(ch-'a'));
            }
        }
        int maxlen=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if((temp[i] & temp[j])==0){
                    int len=words[i].size()*words[j].size();
                    maxlen=max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};