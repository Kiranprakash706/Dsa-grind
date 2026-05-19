class NumMatrix {
public:
vector<vector<int>>temp;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=1;j<matrix[i].size();j++){
                matrix[i][j]=matrix[i][j-1]+matrix[i][j];
            }
        }
        temp=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        for(int i=row1;i<=row2;i++){
           
                if(col1==0){
                    ans+=temp[i][col2];
                }
                else{
                    ans+=(temp[i][col2]-temp[i][col1-1]);
                }

            
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */