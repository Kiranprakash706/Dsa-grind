class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>>arr;
        for(int i=0;i<tasks.size();i++){
           arr.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(arr.begin(), arr.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        int i=0;
        long long time=0;
        vector<int> result;
        while(result.size()<n){
            while(i<n && arr[i][0]<=time){
                pq.push({arr[i][1],arr[i][2]});
                i++;
            }
            if(pq.empty()){
                time=arr[i][0];
            }
            else{
               auto a=pq.top();
                pq.pop();
                time+=(long long)a[0];
                result.push_back(a[1]);
            }
        }
        return result;

    }
};