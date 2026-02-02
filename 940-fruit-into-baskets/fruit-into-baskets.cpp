class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int , int > mapp;
        int l=0;
    
        int maxlen=0;
        for(int r=0;r<fruits.size();r++){
           mapp[fruits[r]]++;
           
            if(mapp.size()>2){
                mapp[fruits[l]]--;
                if(mapp[fruits[l]]==0){
                    mapp.erase(fruits[l]);
                }
                l++;
            }
            if(mapp.size()<=2){
            maxlen=max(maxlen,r-l+1);
            }
            }
        
        return maxlen;

    }
};