class Solution {
public:
    int trailingZeroes(int n) {
        if(n<0){
            return 0;
        }
        int cnt=0;
        for(int i=5;n/i>=1;i*=5){
            int temp=n/i;
            cnt+=temp;
        }
        return cnt;
    }
};