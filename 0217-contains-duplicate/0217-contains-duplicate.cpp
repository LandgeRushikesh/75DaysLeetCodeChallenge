#include<map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto ele:mpp){
            if(ele.second>=2){
                return true;
            }
        }
        return false;
    }
};