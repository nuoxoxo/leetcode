class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>   res;
        for (string sub: words)
        {
            for (string w: words)
            {
                if (w != sub && w.find(sub) != string::npos)
                {
                    res.push_back(sub);
                    break ;
                }
            }
        }
        return res;
    }
};
