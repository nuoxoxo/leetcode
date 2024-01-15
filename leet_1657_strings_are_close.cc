class Solution {
public:
    bool closeStrings(string word1, string word2) {

        if (word1.length() ^ word2.length())
            return false;

        set<char> set1(word1.begin(), word1.end()), 
            set2(word2.begin(), word2.end());
        if (set1 != set2)
            return false;

        vector<int> dict1(26, 0), dict2(26, 0);
        int i = -1;
        while (++i < word1.length()) {
            dict1[word1[i] - 'a']++, dict2[word2[i] - 'a']++;
        }
        sort(dict1.begin(), dict1.end());
        sort(dict2.begin(), dict2.end());
        return dict1 == dict2;
    }
};
