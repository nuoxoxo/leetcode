class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string>  res;
        for (string & w: words)
        {
            if (checker("qwertyuiop", w) || checker("asdfghjkl", w) || checker("zxcvbnm", w))
                res.push_back(w);
        }
        return res;
    }

    bool checker (const string charset, string & word)
    {
        for (char c: word)
        {
            if (find(charset.begin(), charset.end(), tolower(c)) == charset.end())
            {
                // cout << c << ' ' << word << ' ' << charset << endl;
                return false;
            }
        }
        return true;
    }
};
