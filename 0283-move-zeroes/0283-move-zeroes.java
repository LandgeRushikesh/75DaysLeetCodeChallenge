class Solution {
    public void moveZeroes(int[] nums) {
        // First find 1st Zero
        int n = nums.length;
        int i = -1;
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                i = j;
                break;
            }
        }

        if(i==-1){
            return;
        }

        for(int j=i+1;j<n;j++){
            if(nums[j]!=0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
    }
}