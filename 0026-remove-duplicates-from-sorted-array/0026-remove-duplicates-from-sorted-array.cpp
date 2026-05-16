class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int i=0;
        // int n = nums.size();
        // for(int j=1;j<n;j++){
        //     if(nums[i]!=nums[j]){
        //         i++;
        //         nums[i] = nums[j];// we are not swapping because we don't care about that value at i which is a duplicate one so we are just replacing it with unique value
        //     }
        // }

        // return i+1;

        int i=0;
        int n = nums.size();

        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};