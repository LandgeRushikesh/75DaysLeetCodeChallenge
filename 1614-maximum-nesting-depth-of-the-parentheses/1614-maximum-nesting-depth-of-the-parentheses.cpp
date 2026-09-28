class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int cnt = 0;
        int max_cnt = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                max_cnt = max(max_cnt,cnt);
            }
            else if(s[i]==')'){
                cnt--;
            }
        }

        return max_cnt;
    }
};