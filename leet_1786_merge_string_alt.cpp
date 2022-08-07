class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string  res = "";
        int     i = -1;
        while (++i < word1.length() && i < word2.length())
            res = res + word1[i] + word2[i] ;
        return res + word1.substr(i) + word2.substr(i); 
    }
};
