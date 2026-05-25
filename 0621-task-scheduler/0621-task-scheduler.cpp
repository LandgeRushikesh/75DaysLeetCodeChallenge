class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        
        // Count frequency
        for(char t : tasks) {
            freq[t - 'A']++;
        }
        
        // Find max frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        
        // Count how many tasks have max frequency
        int countMax = 0;
        for(int f : freq) {
            if(f == maxFreq) countMax++;
        }
        
        // Apply formula
        int partCount = maxFreq - 1;
        int partLength = n + 1;
        
        int result = partCount * partLength + countMax;
        
        return max((int)tasks.size(), result);
    }
};