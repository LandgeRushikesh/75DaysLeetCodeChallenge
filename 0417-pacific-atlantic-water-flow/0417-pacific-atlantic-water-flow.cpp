class Solution {
public:
    int m, n;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c, vector<vector<bool>>& vis,
             vector<vector<int>>& heights) {

        vis[r][c] = true;

        for (auto &d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (vis[nr][nc])
                continue;

            // Reverse flow condition
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, vis, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific (top row + left column)
        for (int i = 0; i < m; i++)
            dfs(i, 0, pac, heights);

        for (int j = 0; j < n; j++)
            dfs(0, j, pac, heights);

        // Atlantic (bottom row + right column)
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, atl, heights);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, atl, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};