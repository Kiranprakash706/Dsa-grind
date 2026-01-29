class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>>rows(9),col(9),boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch=='.'){
                    continue;
                }
                if(rows[i].count(ch)){
                    return false;
                }
                rows[i].insert(ch);

                if(col[j].count(ch)){
                    return false;
                }
                col[j].insert(ch);
                int index=(i/3)*3+(j/3);
                if(boxes[index].count(ch)){
                    return false;
                }
                boxes[index].insert(ch);
            }
        }
        return true;
    }
};