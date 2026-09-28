class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // vector<int> n1;
        // vector<int> n2;

        // for(int i=0;i<n;i++){
        //     n1.push_back(nums[i]);
        //     n2.push_back(nums[i+n]);
        // }
        // int j=0;
        // int k=1;
        // for(int i=0;i<n;i++){
        //     nums[j] = n1[i];
        //     nums[k] = n2[i];
        //     j += 2;
        //     k += 2;
        // }

        // return nums;

        /*
        Time Complexity - O(2n)

        Space Complexity - O(n)
        */

        vector<int> ans(2*n,0);

        for(int i=0;i<n;i++){
            ans[i * 2] = nums[i];
            ans[i * 2 + 1] = nums[i+n];
        }

        return ans;

        /*
        Time Complexity - O(n)

        Space Complexity - O(n)
        */
    }
};