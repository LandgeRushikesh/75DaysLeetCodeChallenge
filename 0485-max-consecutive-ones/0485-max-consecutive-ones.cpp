class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int max_cnt = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;
                max_cnt = max(max_cnt,cnt);
            }
            else{
                cnt = 0;
            }
        }

        return max_cnt;
    }
};