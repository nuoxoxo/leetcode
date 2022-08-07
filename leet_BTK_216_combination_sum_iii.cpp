class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> v;
        vector<int>         c; // current
        backtracking(v, c, 1, k, n);
        return v;
    }
    
    void backtracking(vector<vector<int>>& v, vector<int>& c, int count, int k, int n)
    {
        if (n < 0 || c.size() > k)
            return;
        if (!n && c.size() == k)
            v.push_back(c);
        else
        {
            int i = count - 1;
            while (++i < 10)
            {
                c.push_back(i);
                backtracking(v, c, i + 1, k, n - i);
                c.pop_back();
            }
        }
    }
};
