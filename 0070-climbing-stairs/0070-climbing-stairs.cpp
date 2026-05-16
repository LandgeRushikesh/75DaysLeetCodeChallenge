class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n<=2){
            return n;
        }

        if(dp[n]!=-1){
            return dp[n];
        }
        int firstans = helper(n-1);
        int Secondans = helper(n-2);

        dp[n] = firstans + Secondans;

        return firstans + Secondans;
    }
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};