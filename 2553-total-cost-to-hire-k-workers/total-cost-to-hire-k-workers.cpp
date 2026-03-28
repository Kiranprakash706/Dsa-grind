class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int left=0;
        int right=costs.size()-1;
        priority_queue<int , vector<int> , greater<int>>pq1;
         priority_queue<int , vector<int> , greater<int>>pq2;
         for(int i=0;i<candidates && left<=right;i++){
            pq1.push(costs[left++]);
         }
         for(int i=0;i<candidates && left<=right;i++){
            pq2.push(costs[right--]);
         }
         while(k--){
           if(!pq1.empty() && !pq2.empty()){
             if (pq1.top() <= pq2.top()) {
                    ans += pq1.top();
                    pq1.pop();

                    if (left <=right) {
                        pq1.push(costs[left++]);
                    }
                } else {
                    ans += pq2.top();
                    pq2.pop();

                    if (left <= right) {
                        pq2.push(costs[right--]);
                    }
                }
           }
            else if (!pq1.empty()) {
                ans += pq1.top();
                pq1.pop();

                if (left <= right) {
                    pq1.push(costs[left++]);
                }
            }
            else {
                ans += pq2.top();
                pq2.pop();

                if (left <= right) {
                    pq2.push(costs[right--]);
                }
            }
         }
         return ans;
    }
};