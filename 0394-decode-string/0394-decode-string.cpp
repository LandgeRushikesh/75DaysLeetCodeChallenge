class Solution {
public:
    string solve(string &s,int &idx){
        string res = "";

        while(idx<s.length()){
            if(s[idx]==']'){
                return res;
            }
            // normal char
            if(isalpha(s[idx])){
                res+= s[idx];
                idx++;
            }
            
            // digit
            else if(isdigit(s[idx])){
                int num = 0;

                while(isdigit(s[idx])){
                    num = num * 10 + (s[idx]-'0');
                    idx++;
                }

                idx++;//skip '['

                string temp = solve(s,idx);

                while(num>0){
                    res += temp;
                    num--;
                }

                idx++;//skip ']'
            }
        }

        return res;
    }
    string decodeString(string s) {
        int idx = 0;
        return solve(s,idx);
    }
};