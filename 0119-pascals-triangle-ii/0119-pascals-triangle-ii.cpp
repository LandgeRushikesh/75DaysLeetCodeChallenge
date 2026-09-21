class Solution {
public:
    // vector<int> getRow(int rowIndex) {
    //     vector<vector<int>> triangle;
    //     for(int i=0;i<=rowIndex;i++){
    //         triangle.push_back({});// this is to create a row in vector as we cannot access vector using indices as it's size will be zero so it will give reference to NULL error.
    //         for(int j=0;j<=i;j++){
    //             if(j==0 || j==i){

    //                 triangle[i].push_back(1);
    //                 continue;
    //             }

    //             int ele = triangle[i-1][j] + triangle[i-1][j-1];

    //             triangle[i].push_back(ele);
    //         }
    //     }

    //     return triangle[rowIndex];
    // }
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            return {1};
        }
        vector<int> prev_row = {1};
        vector<int> curr_row;
        for(int i=1;i<=rowIndex;i++){
            curr_row.clear();
            curr_row.resize(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    curr_row[j] = 1;
                    continue;
                }

                int ele = prev_row[j] + prev_row[j-1];
                curr_row[j] = ele;
            }
            prev_row = curr_row;
        }
        return curr_row;
    }
};