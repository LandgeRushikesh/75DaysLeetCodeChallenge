class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int sum = 0;

        for(int right = 0; right < n; right++) {

            sum += nums[right];

            while(sum >= target) {

                int len = right - left + 1;
                minLen = min(minLen, len);

                sum -= nums[left];
                left++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};