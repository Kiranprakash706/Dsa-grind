class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int>pref(customers.size()+1,0);
        vector<int>suff(customers.size()+1,0);
        for(int i=0;i<customers.length();i++){
           
                if(customers[i]=='N'){
                    pref[i+1]=pref[i]+1;
                }
                else{
                    pref[i+1]=pref[i];
                }
            
        }
        for(int i=customers.length()-1;i>=0;i--){
           
                if(customers[i]=='Y'){
                    suff[i]=suff[i+1]+1;
                }
                else{
                    suff[i]=suff[i+1];
                }
            
        }
        int sum=INT_MAX;
        int ans=-1;
        for(int i=0;i<pref.size();i++){
            int temp=pref[i]+suff[i];
            if(temp<sum){
                sum=temp;
                ans=i;
            }
        }
        return ans;

    }
};