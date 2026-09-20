class Solution {
public:
// Brute Force Approach -

/*
    void setRowColZero(vector<vector<int>>& matrix,int row,int col){//in params the row and col is just a number of row and column which we have to modify
        int row_size = matrix.size();
        int col_size = matrix[0].size();
        // set row zero

        for(int j=0;j<col_size;j++){
            matrix[row][j] = 0;
        }

        // set col zero
        for(int i=0;i<row_size;i++){
            matrix[i][col] = 0;
        }

    }


    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<bool>> check(row,vector<bool>(col,false));

        // check where is zero
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    check[i][j] = true;
                }
            }
        }

        // check for zero's position and set that row and column to zero
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(check[i][j] == true){
                    setRowColZero(matrix,i,j);
                }
            }
        }
    }

*/
void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<bool> rows(row,false);
        vector<bool> cols(col,false);

        // Here if matrix[i][j] is 0 then set particular row and col in specified vector as zero
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        // now traverse matrix if particular row or col has zero then set the particular matrix[i][j] = 0
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};