class Solution {
public:
    // Brute Force Approach - 
    // vector<int> sortedSquares(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         nums[i] = nums[i]*nums[i];
    //     }

    //     sort(nums.begin(),nums.end());
    //     return nums;
    // }

    /*
    Time Complexity - O(nlogn)

    Space Complexity - O(1)
    */


    // Optimize approach - as we know largest square will come from either:
    // left(negative largest)
    // right (positive largest)

    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int left = 0;
        int right = n-1;
        int pos = n-1;

        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[pos] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[pos] = nums[right]*nums[right];
                right--;
            }
            pos--;
        }

        return ans;
    }
};