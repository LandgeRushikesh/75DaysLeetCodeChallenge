#include<set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        int maxLen = 1;
        int left = 0;
        int right = 0;
        set<int> unique;
        while(right<n){
            if(unique.find(s[right])==unique.end()){
                maxLen = max(maxLen,right-left+1);
                unique.insert(s[right]);
                right++;
            }
            else{
                unique.erase(s[left]);
                left++;
            }
        }

        return maxLen;
    }
};