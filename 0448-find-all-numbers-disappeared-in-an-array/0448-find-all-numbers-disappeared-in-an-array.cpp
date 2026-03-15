class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        // Brute Force Aproach
        // int n = nums.size();
        // vector<int> ans;

        // for(int i=1;i<=n;i++){
        //     bool missing = true;
        //     for(int j=0;j<n;j++){
        //         if(nums[j]==i){
        //             missing = false;
        //         }
        //     }
        //     if(missing){
        //         ans.push_back(i);
        //     }
        // }

        // return ans;

        /*
        Time Complexity - O(n^2)

        Space Complexity - O(n)
        */

        // Better Approach

        // int n = nums.size();
        // vector<int> Freq(n+1,0);
        // vector<int> missing;

        // for(int i=0;i<n;i++){
        //     Freq[nums[i]]++;
        // }

        // for(int j=1;j<Freq.size();j++){
        //     if(Freq[j]==0){
        //         missing.push_back(j);
        //     }
        // }

        // return missing;

        /*
        Time Complexity - O(n)

        Space Complexity - O(n)
        */

        // Optimal Approach -
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            // Mark the index as -ve as there element is present
            int index=abs(nums[i])-1;
            if(nums[index]>0){
                nums[index] = -nums[index];
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }

        return ans;
        /*
        Time Complexity - O(n)

        Space Complexity - O(1)
        */
    }
};