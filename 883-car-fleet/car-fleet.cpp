class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double, double>>ans;
        for(int i=0;i<position.size();i++){
            double time=((double)(target-position[i])/(double)speed[i]);
            ans.push_back({position[i], time});
        }
        stack<double>st;
        
       sort(ans.begin(), ans.end());
       reverse(ans.begin(), ans.end());
       for(auto &i:ans){
        if(st.empty() || st.top()<i.second){
            st.push(i.second);
        }
       }
       return st.size();
    }
};