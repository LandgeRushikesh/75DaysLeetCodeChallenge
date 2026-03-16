#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> freq;

        int n = strs.size();
        for(int i=0;i<n;i++){
            string key = strs[i];
            sort(key.begin(),key.end());

            freq[key].push_back(strs[i]);
        }

        for(auto ele:freq){
            ans.push_back(ele.second);
        }

        return ans;
    }
};