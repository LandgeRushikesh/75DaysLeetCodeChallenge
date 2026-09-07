#include<algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> strsMap;

        for(int i=0;i<n;i++){
            string copy = strs[i];
            sort(copy.begin(),copy.end());
            strsMap[copy].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &mp:strsMap){
            ans.push_back(mp.second);
        }

        return ans;
    }
};