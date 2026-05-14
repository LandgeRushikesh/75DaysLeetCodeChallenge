class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // Finding max of piles
        int max = piles[0];
        for(int i=1;i<n;i++){
            if(piles[i]>max){
                max = piles[i];
            }
        }

        // Binary search
        int low = 1;
        int high = max;
        int res = max;

        while(low<=high){
            int mid = low +(high-low)/2;
            long long hours = 0;
            for(int i=0;i<n;i++){
                hours += ((long long)piles[i] + mid - 1) / mid;
            }

            if(hours<=h){
                res = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return res;
    }
};