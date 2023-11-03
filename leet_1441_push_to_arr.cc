class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n)
    {
        vector<string>  res;
        int cur = 0;
        int i = 0;
        while (++i && cur ^ (int) target.size())
        {
            if (target[cur] == i)
            {
                res.push_back("Push");
                cur++;
            }
            else
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};
