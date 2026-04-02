#include<stack>
#include<unordered_map>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> temp;
        for(int i=n-1;i>=0;i--){
            while(!temp.empty() && temperatures[temp.top()]<=temperatures[i]){
                temp.pop();
            }

            int idx = !temp.empty()?temp.top():-1;

            ans[i] = idx==-1?0:temp.top()-i;

            temp.push(i);
        }
        return ans;
    }
};