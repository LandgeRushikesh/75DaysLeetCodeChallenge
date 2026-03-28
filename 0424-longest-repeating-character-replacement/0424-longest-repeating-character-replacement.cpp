class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.length();
        int left = 0;
        int right = 0; 
        int maxFreq = 0;
        int maxLen = 0;

        while(right<n){
            freq[s[right]-'A']++;
            int windowSize = right - left + 1;
            maxFreq = max(maxFreq,freq[s[right]-'A']);

            if(windowSize-maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen,right - left + 1);
            right++;
        }
        return maxLen;
    }
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)---> as freq has constant size 26
    */
};