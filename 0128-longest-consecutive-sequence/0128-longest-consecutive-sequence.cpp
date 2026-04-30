#include<set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int longest = 1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto i:st){
            if(st.find(i-1) == st.end()){
                int x = i;
                int count = 1;
                while(st.find(x+1)!=st.end()){
                    x = x+1;
                    count++;
                }
                longest = max(longest,count);
            }
        }
        return longest;
    }
};