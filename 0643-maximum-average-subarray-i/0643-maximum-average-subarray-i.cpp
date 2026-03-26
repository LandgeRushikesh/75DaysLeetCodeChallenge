#include<climits>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double average = 0;
        double maxAverage = INT_MIN;
        int sum = 0;

        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        average = (double)sum/k;
        maxAverage = max(maxAverage,average);
        if(k==n){
            return maxAverage;
        }

        for(int i=k;i<n;i++){
            sum -= nums[i-k];
            sum += nums[i];
            average = (double)sum/k;
            maxAverage = max(average,maxAverage);
        }

        return maxAverage;
    }
};