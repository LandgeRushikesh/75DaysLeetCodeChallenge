class Solution {
public:
    bool SearchInRow(vector<vector<int>>& matrix,int row,int col, int target){
        int sRow = 0;
        int eRow = col-1;

        while(sRow<=eRow){
            int mid = (sRow + eRow)/2;

            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                sRow = mid+1;
            }
            else{
                eRow = mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int startOfRow = 0;
        int EndOfRow = row-1;

        while(startOfRow<=EndOfRow){
            int midOfRow = (startOfRow + EndOfRow)/2;

            if(matrix[midOfRow][0]<=target && matrix[midOfRow][col-1]>=target){
                return SearchInRow(matrix,midOfRow,col,target);
            }
            else if(matrix[midOfRow][0]<target){
                startOfRow = midOfRow+1;
            }
            else{
                EndOfRow = midOfRow-1;
            }
        }
        return false;
    }
};