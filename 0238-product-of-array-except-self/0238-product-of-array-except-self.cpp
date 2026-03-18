class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute Force Approach

        // int n = nums.size();
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //         int product = 1;
        //         for(int j=0;j<n;j++){
        //             if(i==j){
        //                 continue;
        //             }
        //             product *=nums[j];
        //         }
        //         ans.push_back(product);
        // }
        // return ans;

        /*
        Time Complexity - O(n^2)

        Space Complexity - O(1)
        */

        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);

        // Calculate prefix
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }

        // Calculate Suffix
        for(int i=n-2;i>=0;i--){
            suffix[i] = suffix[i+1]*nums[i+1];
        }

        // Calculate Product
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i] = prefix[i]*suffix[i];
        }

        return ans;
    }
};