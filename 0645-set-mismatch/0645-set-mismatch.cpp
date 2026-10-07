#include<unordered_map>
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> freq;
        int repeated = -1;

        for(int i=0;i<n;i++){
            if(freq.find(nums[i])!=freq.end()){
                repeated = nums[i];
                break;
            }
            freq.insert(nums[i]);
        }

        // Missing
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        int totalSum = (n*(n+1))/2;
        int missing = totalSum - (sum - repeated);

        return {repeated,missing};
    }
};