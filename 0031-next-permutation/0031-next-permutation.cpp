class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int brkp = -1;

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                brkp = i;
                break;
            }
        }

        if(brkp == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int min = brkp;
        for(int i=n-1;i>brkp;i--){
            if(nums[i]>nums[min]){
                min = i;
                break;
            }
        }

        swap(nums[min],nums[brkp]);

        reverse(nums.begin()+brkp+1,nums.end());
    }
};