class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }

        int count = 0;
        int diff = n-999;
        count += diff;

        return count;
    }
};