#include<unordered_map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                return true;
            }
        }

        // We don't need this second loop as we can do this thing inside single loop
        // for(auto ele:mpp){
        //     if(ele.second>=2){
        //         return true;
        //     }
        // }
        return false;
    }

    /*
    Time Complexity - O(n)

    Space Complexity - O(n)
    */
};