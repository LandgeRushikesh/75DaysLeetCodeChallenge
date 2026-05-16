class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums,int i){
        int n = nums.size();

        if(i>=n){
            return 0;
        } 

        if(dp[i]!=-1){
            return dp[i];
        }

        int take = nums[i] + helper(nums,i+2); 
        int skip = helper(nums,i+1); 

        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,-1);
        
        return helper(nums,0);
    }
};