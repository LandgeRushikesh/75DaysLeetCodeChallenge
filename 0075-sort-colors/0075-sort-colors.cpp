class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        for(int i=0;i<n;i++){
            if(nums[mid]==0){
                int temp=nums[low];
                nums[low]=nums[mid];
                nums[mid]=temp;
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                int temp=nums[high];
                nums[high]=nums[mid];
                nums[mid]=temp;
                high--;
            }
        }
    }
};