class TrieNode {
public:
    bool        ended;
    TrieNode *  branch[26];

    TrieNode()
    {
        ended = false;
        int i = -1;
        while (++i < 26)
            branch[i] = nullptr;
    }
};

class Trie {
public:

    TrieNode * node;

    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * cur = node;
        for (char c: word) {
            if ( cur->branch[c - 'a'] == nullptr )
                cur->branch[c - 'a'] = new TrieNode();
            cur = cur->branch[c - 'a'];
        }
        cur->ended = true;
    }
    
    bool search(string word) {
        TrieNode * cur = node;
        for (char c: word) {
            if ( cur->branch[c - 'a'] == nullptr )
                return false;
            cur = cur->branch[c - 'a'];
        }
        return cur->ended;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = node;
        for (char c: prefix) {
            if ( cur->branch[c - 'a'] == nullptr )
                return false;
            cur = cur->branch[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
