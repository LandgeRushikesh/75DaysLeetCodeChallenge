class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique;
        int n = digits.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            // First digit cannot be zero
            if(digits[i]==0){
                continue;
            }

            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int num = 0;
                    // last digit must be even
                    if(digits[k]%2!=0){
                        continue;
                    }
                    // all indices should be different
                    if(i==j || j==k ||i==k){
                        continue;
                    }
                    num = num *10 + digits[i];
                    num = num *10 + digits[j];
                    num = num *10 + digits[k];

                    if(num%2==0){
                        if(unique.find(num)==unique.end()){
                            cnt++;
                            unique.insert(num);
                        }

                    }
                }
            }
        }
        return cnt;
    }
};