class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double , pair<int  , int >>,vector<pair<double , pair<int , int>>>, greater<pair<double , pair<int , int >>>>pq;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            double temp=sqrt(x*x +y*y);
            pq.push({temp,{x,y}});
        } 
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            int xx=pq.top().second.first;
            int yy=pq.top().second.second;
            ans.push_back({xx,yy});
            pq.pop();
        }
        return ans;
    }
};