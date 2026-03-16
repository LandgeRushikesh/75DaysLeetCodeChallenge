#include<unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Better Approach

        // vector<vector<string>> ans;
        // unordered_map<string,vector<string>> freq;

        // int n = strs.size();
        // for(int i=0;i<n;i++){
        //     string key = strs[i];
        //     sort(key.begin(),key.end());

        //     freq[key].push_back(strs[i]);
        // }

        // for(auto ele:freq){
        //     ans.push_back(ele.second);
        // }

        // return ans;

        /*
        Time Complexity - O(n* k logk)
        where,
            n = no.of words
            k =length of word

        Space Complexity = O(n*k)
        */

        // Optimal Approach - 
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> ans;
        for(string s:strs){
            vector<int> freq(26,0);

            // Count the Frequency of characters in each word 
            for(char ch:s){
                freq[ch - 'a']++;
            }
            // Genrate the key
            string key = "";
            for(int i=0;i<26;i++){
                key += to_string(freq[i])+"#";
            }
            mpp[key].push_back(s);
        }

        for(auto ele:mpp){
            ans.push_back(ele.second);
        }

        return ans;
    }
};