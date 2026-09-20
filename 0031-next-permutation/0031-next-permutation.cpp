class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int brkp = -1;

        for(int i=n-2;i>=0;i--){//O(n)
            if(nums[i]<nums[i+1]){
                brkp = i;
                break;
            }
        }

        if(brkp == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int swapIdx = brkp;
        for(int i=n-1;i>brkp;i--){//O(n)
            if(nums[i]>nums[swapIdx]){
                swapIdx = i;
                break;
            }
        }

        swap(nums[swapIdx],nums[brkp]);

        reverse(nums.begin()+brkp+1,nums.end());//O(n)

        /*
        Time Complexity - O(3n)--> O(n)

        Space Complexity - O(1)
        */
    }
};