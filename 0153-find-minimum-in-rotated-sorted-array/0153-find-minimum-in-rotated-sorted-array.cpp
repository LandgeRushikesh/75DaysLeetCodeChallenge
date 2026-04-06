class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int minVal  = nums[high];

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[low]<=nums[mid]){
                minVal = min(nums[low],minVal);
                low = mid+1;
            }
            else if(nums[high]>=nums[mid]){
                minVal = min(nums[mid],minVal);
                high = mid-1;
            }
        }
        return minVal;
    }
};