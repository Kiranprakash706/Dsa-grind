class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int  n=rooms.size();
        vector<bool >visit(n,false);
        queue<int >q;
        q.push(0);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(!visit[a]){
                visit[a]=true;
                for(auto &i:rooms[a]){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<visit.size();i++){
            if(visit[i]==false){
                return false;
            }
        }
        return true;
    }
};