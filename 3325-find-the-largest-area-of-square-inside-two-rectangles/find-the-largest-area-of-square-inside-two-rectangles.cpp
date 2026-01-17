class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long bestSide = 0;

        for(int i = 0; i < n; i++) {
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];

            for(int j = i + 1; j < n; j++) {
                int x3 = bottomLeft[j][0];
                int y3 = bottomLeft[j][1];
                int x4 = topRight[j][0];
                int y4 = topRight[j][1];

                int left = max(x1, x3);
                int right = min(x2, x4);
                if (right - left <= bestSide) continue; // ❌ prune

                int bottom = max(y1, y3);
                int top = min(y2, y4);
                if (top - bottom <= bestSide) continue; // ❌ prune

                int side = min(right - left, top - bottom);
                bestSide = max(bestSide, (long long)side);
            }
        }

        return bestSide * bestSide;
    }
};