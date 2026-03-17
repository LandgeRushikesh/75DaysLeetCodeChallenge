class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }

        vector<vector<int>> arr(n+1);
        for(auto ele:freq){
            arr[ele.second].push_back(ele.first);
        }

        vector<int> ans;
        for(int i=n;i>0;i--){
            for(auto ele:arr[i]){
                ans.push_back(ele);
                if(ans.size()==k){
                    return ans;
                }

            }
        }
        return ans;
    }
};