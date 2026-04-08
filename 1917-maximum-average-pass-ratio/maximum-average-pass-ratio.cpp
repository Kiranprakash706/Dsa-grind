class Solution {
public:
double gain(double p, double t){
    return (double)(t-p)/(t*(t+1));
}
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       priority_queue<tuple<double , int , int >> pq;
       for(int i=0;i<classes.size();i++){
        double p=classes[i][0];
        double t=classes[i][1];
        pq.emplace(gain(p,t), p,t );
       }
       while(extraStudents--){
        auto [val, p, t]=pq.top();
        pq.pop();
        p++;
        t++;
        pq.emplace(gain(p,t), p, t);
       }
       double ans=0.0;
       while(!pq.empty()){
        auto [val, p, t]=pq.top();
        ans+=(double)p/t;
        pq.pop();
       }
       return ans/classes.size();

    }
};