class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> n1;
        vector<int> n2;

        for(int i=0;i<n;i++){
            n1.push_back(nums[i]);
            n2.push_back(nums[i+n]);
        }
        int j=0;
        int k=1;
        for(int i=0;i<n;i++){
            nums[j] = n1[i];
            nums[k] = n2[i];
            j += 2;
            k += 2;
        }

        return nums;
    }
};