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
        for(int i=n;i>=0;i--){
            for(int j=0;j<arr[i].size();j++){
                if(ans.size()==k){
                    return ans;
                }

                ans.push_back(arr[i][j]);
            }
        }
        return ans;
    }
};