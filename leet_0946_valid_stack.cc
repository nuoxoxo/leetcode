class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        vector<int> a;
        int     idx = 0;
        for (int n: pushed)
        {
            a.push_back(n);
            while (!a.empty() && a[a.size() - 1] == popped[idx])
            {
                a.pop_back();
                ++idx;
            }
        }
        return a.size() == 0;
    }
};
