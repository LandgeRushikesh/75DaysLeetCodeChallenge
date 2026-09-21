class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        for(int i=0;i<=rowIndex;i++){
            triangle.push_back({});// this is to create a row in vector as we cannot access vector using indices as it's size will be zero so it will give reference to NULL error.
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){

                    triangle[i].push_back(1);
                    continue;
                }

                int ele = triangle[i-1][j] + triangle[i-1][j-1];

                triangle[i].push_back(ele);
            }
        }

        return triangle[rowIndex];
    }
};