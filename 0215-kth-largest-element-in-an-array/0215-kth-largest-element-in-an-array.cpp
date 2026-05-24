class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());

        // return nums[n-k];


        priority_queue<int, vector<int>, greater<int>> pq;

        for(int num : nums) {

            // Insert element
            pq.push(num);

            // Keep heap size only k
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Top element = kth largest
        return pq.top();
    }
};