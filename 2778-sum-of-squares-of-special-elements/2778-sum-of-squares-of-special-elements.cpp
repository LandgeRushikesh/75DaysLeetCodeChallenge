class Solution {
public:
    int squareNum(int n){
        return n*n;
    }
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int squareSum = 0;
        for(int i=0;i<n;i++){
            if(n%(i+1)==0){
                squareSum += squareNum(nums[i]);
            }
        }

        return squareSum;
    }
};