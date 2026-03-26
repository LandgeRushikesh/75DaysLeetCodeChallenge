#include<climits>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double average = 0;
        int sum = 0;

        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        average = (double)sum/k;
        double maxAverage = average;
        
        for(int i=k;i<n;i++){
            sum -= nums[i-k];
            sum += nums[i];
            average = (double)sum/k;
            maxAverage = max(average,maxAverage);
        }

        return maxAverage;
    }
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};