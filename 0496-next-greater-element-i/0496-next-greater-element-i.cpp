class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> mpp;
        stack<int> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            int NG = 0;
            if(st.empty()){
                NG = -1;
            }
            else{
                NG = st.top();
            }

            mpp[nums2[i]] = NG;
            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};