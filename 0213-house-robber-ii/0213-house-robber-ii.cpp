class Solution {
public:
    vector<int> dp;
    int helper(vector<int>& nums,int i){
        int n = nums.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int take = nums[i]+helper(nums,i+2);
        int skip = helper(nums,i+1);

        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                temp1.push_back(nums[i]);
            }
            if(i!=0){
                temp2.push_back(nums[i]);
            }
        }
        dp.resize(n+1,-1);
        int ans1 = helper(temp1,0);
        dp.assign(n+1,-1);
        int ans2 = helper(temp2,0);

        return max(ans1,ans2);
    }
};