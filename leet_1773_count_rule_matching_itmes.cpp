class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        string  t, c, n;
        int res = 0;

        for (vector<string> i : items)
        {
            t = i[0];
            c = i[1];
            n = i[2];
            if ((ruleKey == "type" && t == ruleValue) ||
                (ruleKey == "color" && c == ruleValue) ||
                (ruleKey == "name" && n == ruleValue))
                res++;
        }
        return res;
    }
};
