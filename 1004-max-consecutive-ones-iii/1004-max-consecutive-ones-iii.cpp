class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int freq = 0;
        int maxLen = 0;


        for(int right = 0;right<n;right++){
            if(nums[right]==1){
                freq++;
            }

            int windowSize = right - left + 1;

            if(windowSize-freq > k){
                if(nums[left]==1){
                    freq--;
                }
                left++;
            }

            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
    /*
    Time Complexity: O(n) → each element visited once
    Space Complexity: O(1)
    */
};