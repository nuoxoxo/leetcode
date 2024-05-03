class Solution {
public:
    string reversePrefix(string word, char ch) {
        vector<string(*)(string, char)> solutions {
            // using_find,
            shorter,
        };
        return solutions[0](word, ch);
    }

    static string shorter(string word, char c) {
        reverse(word.begin(), word.begin() + word.find(c) + 1);
        return word;
    }

    static string using_find(string word, char c) {
        auto index = word.find(c);
        if (index != string::npos)
            reverse(word.begin(), word.begin() + index + 1);
        return word;
    }
};
