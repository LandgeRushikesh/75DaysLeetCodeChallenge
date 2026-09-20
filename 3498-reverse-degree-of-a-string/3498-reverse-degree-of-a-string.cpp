class Solution {
public:
    int reverseDegree(string s) {
        int rev_deg = 0;
        for(int i=0;i<s.length();i++){
            int rev_pos = 'z' - s[i] +1;
            rev_deg += rev_pos * (i+1);
        }

        return rev_deg;
    }
};