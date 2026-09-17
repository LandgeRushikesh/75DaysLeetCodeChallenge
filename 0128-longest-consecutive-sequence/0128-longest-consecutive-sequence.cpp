#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            seq.insert(nums[i]);
        }


        int max_len = 0;
        for(auto x:seq){
            // Check if nums[i] is a beginning of the sequence
            if(seq.find(x-1)==seq.end()){
                    int len = 1;
                    int current = x;
                while(seq.find(current+1)!=seq.end()){
                    len++;
                    current += 1;
                }
                max_len = max(len,max_len);
                len = 0;
            }
        }
        return max_len;
    }
};