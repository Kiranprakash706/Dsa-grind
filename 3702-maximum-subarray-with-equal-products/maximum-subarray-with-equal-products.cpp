class Solution {
public:
__int128  gcd(__int128 a, __int128 b){
    if(b==0){
        return a;

    }
    else{
        return gcd(b,a%b);
    }
}
__int128  LCM(__int128  a, __int128  b){
    return a / gcd(a, b) * b;
}
 
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
       
        for(int i=0;i<nums.size();i++){
        __int128   prod=1;
        __int128  gc=0;
        __int128   lc=1;
        for(int j=i;j<nums.size();j++){
            prod*=nums[j];
            if(gc==0){
                gc=nums[j];

            }
            else{
                gc=gcd(gc, nums[j]);
            }
            lc = LCM(lc, nums[j]);
            if(prod>1e9 || lc>1e9){
                break;
            }
            if(prod==gc*lc){
                ans=max(ans, j-i+1);
            }
        }
        }
        return ans;
    }
};