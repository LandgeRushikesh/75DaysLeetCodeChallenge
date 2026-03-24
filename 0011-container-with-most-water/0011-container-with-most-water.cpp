class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int area = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while(left<right){
            int w = right - left;
            int h = min(height[left],height[right]);
            area = w * h; 
            maxArea = max(area,maxArea);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return maxArea;
    }

    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};