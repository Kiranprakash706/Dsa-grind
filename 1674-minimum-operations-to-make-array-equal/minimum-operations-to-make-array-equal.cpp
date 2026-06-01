class Solution {
public:
    int minOperations(int n) {
        if(n==0){
            return 0;
        }
        else{
            return  n*n/4;
        }
    }
};