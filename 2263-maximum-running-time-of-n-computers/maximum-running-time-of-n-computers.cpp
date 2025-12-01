class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        int to_make_equal = batteries.size()-n+1;
        long long available_capacity = 0;
        for(int i=0;i<to_make_equal-1;i++){
            available_capacity = available_capacity + batteries[i];
        }
        long long mul = 1;
        while(to_make_equal<batteries.size()){
            long long diff = batteries[to_make_equal]- batteries[to_make_equal-1];
            if(available_capacity>=mul*diff){
                available_capacity = available_capacity - mul*diff;
                mul++;
                to_make_equal++;
            }
            else{
                return batteries[to_make_equal-1] + available_capacity/mul;
            }
        }

        return batteries[batteries.size()-1] + available_capacity/n;
    }
};