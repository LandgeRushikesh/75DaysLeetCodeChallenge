class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> Freq(n+1,0);
        vector<int> missing;

        for(int i=0;i<n;i++){
            Freq[nums[i]]++;
        }

        for(int j=1;j<Freq.size();j++){
            if(Freq[j]==0){
                missing.push_back(j);
            }
        }

        return missing;
    }
};