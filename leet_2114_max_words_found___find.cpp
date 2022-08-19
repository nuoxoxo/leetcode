class Solution {
public:
    int mostWordsFound(vector<string>& sentences)
    {
        int res = -1;
        int tmp, i;

        for (string s : sentences)
        {
            tmp = 1;
            for (i = 0; (i = s.find(' ', i)) != std::string::npos; i++)
                tmp++;
            if (res < tmp)
                res = tmp;
        }
        return res;
    }
};
