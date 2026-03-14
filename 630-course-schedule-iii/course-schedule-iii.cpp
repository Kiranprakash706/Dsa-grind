class Solution {
public:
    static bool cmd(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  
    }

    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmd);

        priority_queue<int> pq; 
        int duration = 0;

        for(int i=0;i<arr.size();i++){
            int d=arr[i][0];
            int day=arr[i][1];
            if(duration+d<=day){
                pq.push(d);
                duration+=d;
            }
            else if(!pq.empty() && pq.top()>d){
                duration-=pq.top();
                pq.pop();
                duration+=d;
                pq.push(d);
                
            }
        }

        return pq.size();
    }
};