class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=-1;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                k=i;
                break;
            }
        }

        if(k<0){
            return n;
        }

        for(int j=k+1;j<n;j++){
            if(nums[j]!=nums[k]){
                k++;
                swap(nums[j],nums[k]);
            }
        }
        return k+1;
    }
};