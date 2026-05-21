class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
        word = "";
    }
};

class Solution {
public:

    void insertWord(TrieNode* root, string& word) {
        TrieNode* node = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(node->child[idx] == NULL) {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, vector<string>& ans) {

        char ch = board[i][j];

        if(ch == '#' || node->child[ch - 'a'] == NULL) {
            return;
        }

        node = node->child[ch - 'a'];

        // word found
        if(node->word != "") {
            ans.push_back(node->word);

            // avoid duplicates
            node->word = "";
        }

        board[i][j] = '#';

        int rows = board.size();
        int cols = board[0].size();

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 &&
               ni < rows && nj < cols) {

                dfs(board, ni, nj, node, ans);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // build trie
        for(string& word : words) {
            insertWord(root, word);
        }

        vector<string> ans;

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};