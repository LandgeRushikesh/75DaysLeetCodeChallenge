#include<unordered_map>
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        // To find duplicate number
        int duplicate = -1;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for(auto &ele:mpp){
            if(ele.second>1){
                duplicate = ele.first;
                break;
            }
        }

        // To find missing number
        // int missing = -1;
        // int XOR1 = 0;
        // int XOR2= 0;
        // for(int i=0;i<n;i++){
        //     XOR1 = XOR1 ^ i+1; 
        //     XOR2 = XOR2 ^ nums[i];
        // }

        // missing = XOR1^XOR2;


        int missing = -1;
        int totalSum = (n*(n+1))/2;
        totalSum += duplicate;
        int nums_sum = 0;
        for(int i=0;i<n;i++){
            nums_sum += nums[i];
        }

        missing = abs(totalSum - nums_sum);

        return {duplicate,missing};
    }
};