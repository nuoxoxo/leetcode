class Solution {
public:
    int mostWordsFound(vector<string>& sentences)
    {
        int res = -1;
        int tmp;

        for (string s : sentences)
        {
            tmp = 1 + std::count(s.begin(), s.end(), ' ');
            if (res < tmp)
                res = tmp;
        }
        return res;
    }
};
