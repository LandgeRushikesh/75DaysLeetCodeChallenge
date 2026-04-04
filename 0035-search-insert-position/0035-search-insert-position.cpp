class Solution {
public:
    // Brute Force Approach
    // int searchInsert(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==target){
    //             return i;
    //         }
    //         else if(nums[i]>target){
    //             return i;
    //         }
    //     }
    //     return n;
    // }
    
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */

    // Optimal Approach
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
    /*
    Time Complexity - O(log n)

    Space Complexity - O(1)
    */
};