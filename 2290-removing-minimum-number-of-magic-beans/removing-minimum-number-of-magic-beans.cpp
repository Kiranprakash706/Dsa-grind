class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long sum=accumulate(beans.begin(), beans.end(), 0LL);
        sort(beans.begin(), beans.end());
        long long  temp=0;
        long long  ans=LLONG_MAX;
        for(int i=0;i<beans.size();i++){
            if(i==0){
                sum-=beans[i];
                temp=beans[i];
               long long  ans2= sum-beans[i]*(beans.size()-1) ;
               ans=min(ans,ans2);
            }
            else{
                long long  left=temp;
                sum-=beans[i];
                int len=beans.size()-1-i;
                long long ans2=left+(sum-(long long)beans[i]*len);
                ans=min(ans, ans2);
                temp+=beans[i];
            }
        }
        return ans;
    }
};