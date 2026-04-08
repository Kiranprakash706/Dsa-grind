class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladder) {
        priority_queue<int>pq;
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                int diff=heights[i]-heights[i-1];
                if(diff<=bricks){
                    pq.push(diff);
                    bricks-=diff;
                }
                else{
                    if(!pq.empty() && pq.top()>=diff && ladder){
                        bricks+=pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks-=diff;
                        ladder--;
                    }
                    else if(ladder){
                        ladder--;

                    }
                    else{
                        return i-1;
                        break;
                    }
                }
            }
        }
        return heights.size()-1;
    }
};