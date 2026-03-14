#include<unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> freq;
        if(s.length()!= t.length()){
            return false;
        }
        int n = s.length();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }

        for(int i=0;i<n;i++){
            freq[t[i]]--;
            if(freq[t[i]]<0){
                return false;
            }
        }

        return true;
    }
};