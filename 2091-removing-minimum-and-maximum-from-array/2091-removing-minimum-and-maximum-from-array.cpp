class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0;
        int max_idx = 0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[max_idx]){
                max_idx = i;
            }
            else if(nums[i]<nums[min_idx]){
                min_idx = i;
            }
        }
        int min_dist_from_front = min_idx+1;
        int min_dist_from_back = n- min_idx;
        int max_dist_from_front = max_idx+1;
        int max_dist_from_back = n- max_idx;
        
        // find all ways to delete them
        // Both Delete from front
        int dist_both_front = max(min_dist_from_front,max_dist_from_front);

        // Both DELETE from back
        int dist_both_back = max(min_dist_from_back,max_dist_from_back);

        // Min from front and Max From back
        int dist_minf_maxb = min_dist_from_front + max_dist_from_back;

        // Max from and Min From back
        int dist_minb_maxf = min_dist_from_back + max_dist_from_front;

        return min(min(dist_both_front,dist_both_back),min(dist_minf_maxb,dist_minb_maxf));

    }
};