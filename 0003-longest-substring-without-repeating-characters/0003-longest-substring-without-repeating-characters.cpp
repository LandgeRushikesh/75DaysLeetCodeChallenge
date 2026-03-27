#include<set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int left = 0;
        int right = 0;
        set<char> unique;
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
    /*
    Time Complexity - O(n)

    Space Complexity - O(n)
    */
};