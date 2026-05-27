class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Build indegree and outdegree
        for (auto &t : trust) {
            int a = t[0];
            int b = t[1];

            outdegree[a]++;
            indegree[b]++;
        }

        // Find judge
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};