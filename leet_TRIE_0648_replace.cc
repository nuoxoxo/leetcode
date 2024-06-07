class TrieNode {
public:

    map<char, TrieNode *> edges;
    bool isend;

    TrieNode () : isend(false) {}
};

class Trie {
public:

    TrieNode * root;

    Trie (vector<string> & dictionary)
    {
        root = new TrieNode();
        for (string & word : dictionary)
            insert(word);
    }

    void insert(string & word)
    {
        TrieNode * node = root;

        for (char c : word)
        {
            if (node->edges.find(c) == node->edges.end())
                node->edges[c] = new TrieNode();
            node = node->edges[c];
        }
        node->isend = true;
    }

    string find(string & word)
    {
        string  res;
        TrieNode * node = root;

        for (char c : word)
        {
            if (node->edges.find(c) == node->edges.end())
                break ;
            res += c;
            node = node->edges[c];
            if (node->isend)
                return res;
        }
        return word;
    }
};

// solution(s) proper

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        vector<string(*)(vector<string> &, string)> solutions {
            // TLE,
            Using_TRIE,
        };
        return solutions[0](dictionary, sentence);
    }

    static string Using_TRIE(vector<string>& dictionary, string sentence)
    {
        string  res, word;
        Trie trie(dictionary);
        stringstream ss(sentence);

        while (ss >> word)
            res += ' ' + trie.find(word);
        return res.substr(1);
    }

    static string TLE(vector<string>& dictionary, string sentence)
    {
        stringstream ss(sentence);
        string word;
        string res;
        while (ss >> word)
        {
            int shortest = INT_MAX;
            string cand;
            for (string & key : dictionary)
            {
                if (word.find(key) == 0 && key.length() < shortest)
                {
                    shortest = key.length();
                    cand = key;
                }
            }
            if (cand != "")
                word = cand;
            res += ' '  + word;
        }
        return res.substr(1);
    }
};
