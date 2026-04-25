class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};
class WordDictionary {
private:
    TrieNode* root;

    bool searchHelper(string &word, int index, TrieNode* node){
        if(node == nullptr) return false;

        if(index == word.size()){
            return node->isEnd;
        }

        char ch = word[index];

        // Case 1: normal character
        if(ch != '.'){
            int idx = ch - 'a';
            return searchHelper(word, index + 1, node->children[idx]);
        }

        // Case 2: wildcard '.'
        for(int i = 0; i < 26; i++){
            if(node->children[i] != nullptr){
                if(searchHelper(word, index + 1, node->children[i])){
                    return true;
                }
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for(char ch : word){
            int idx = ch - 'a';

            if(node->children[idx] == nullptr){
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */