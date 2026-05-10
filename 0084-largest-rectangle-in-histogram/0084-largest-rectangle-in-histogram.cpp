class Solution {
public:
    // int largestRectangleArea(vector<int>& heights) {
    //     int n = heights.size();
        
    //     int area = 0;
    //     int maxArea = 0;

    //     for(int i=0;i<n;i++){
    //         int left = i;
    //         int right = i;

    //         while(left>0 && heights[left-1]>=heights[i]){
    //             left--;
    //         }
    //         while(right<n-1 && heights[right+1]>=heights[i]){
    //             right++;
    //         }

    //         int l = heights[i];
    //         int w = right - left + 1;
    //         area = l*w;
    //         maxArea = max(area,maxArea);
    //     }
    //     return maxArea;
    // }
    /*
    Time Complexity - O(n^2)

    Space Complexity - O(1)
    */

    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {

            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int rightBoundary = i;
                
                int leftBoundary = st.empty() ? -1 : st.top();

                int width = rightBoundary - leftBoundary - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};