class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int initial=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<initial){
                initial=prices[i];

            }
            else{
                ans=max(ans,abs(initial-prices[i]));
            }
        }
        return ans;
    }
};