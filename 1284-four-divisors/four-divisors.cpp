class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
       int sum=0;
        for(auto num:nums){
            int cnt=0;
            int s1=0;
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    cnt++;
                     int j=num/i;
                s1+=i;
                if(i!=j){
                    cnt++;
                    s1+=j;
                }
                if(cnt>4) break;
                }
  
            }
            if(cnt==4){
                sum+=s1;
            }
            
        }
        return sum;
    }
};