class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visit(n,vector<int >(m,0));
        queue<pair<int, int >>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visit[i][j]=1;
                    break;
                }
            }
            if(!q.empty()){
                break;
            }
        }
        int Perimeter=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        while(!q.empty()){
            pair<int , int>p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0 || newx>n-1 || newy<0 || newy>m-1){
                    Perimeter++;
                }
                else if(grid[newx][newy]==0){
                    Perimeter++;
                }
                else{
                    if(!visit[newx][newy]){
                        visit[newx][newy]=1;
                        q.push({newx, newy});
                    }
                }
                
            }
        }
        return Perimeter;


    }
};