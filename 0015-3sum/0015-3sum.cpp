class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;

       for(int i=0;i<n;i++){
            // Skip Duplicates of i
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;

                    // Skip Duplicates of j
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    // Skip Duplicates of k
                    while(k>j && nums[k]==nums[k+1]){
                        k--;
                    }
                }
                else if(sum<0){
                    j++;
                }
                else{
                    k--;
                }
            }
       }
       return ans;
    }
    /*
    Time Complexity - O(n^2 + nlogn)

    Space Complexity - O(n)
    */
};