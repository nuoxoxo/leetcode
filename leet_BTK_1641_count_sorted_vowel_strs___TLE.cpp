class Solution {
public:
    
    vector<char>    v{'a', 'e', 'i', 'o', 'u'};
    
    int countVowelStrings(int n)
    {
        int res = 0;
        backtracking("", 0, n, res);
        return res ;
    }
    
    void    backtracking(string word, int index, int limit, int& res)
    {
        if (word.length() == limit)
        {
            ++res;
            return;
        }
        else
        {
            int i = index - 1;
            while (++i < 5)
                backtracking(word + v[i], i, limit, res);
        }
    }
};
