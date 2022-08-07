class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        vector<int> E;
        int         i = 0;
        int         lp = popped.size();

        for (int p: pushed)
        {
            E.push_back(p);
            while (!E.empty() && i < lp && E.back() == popped[i])
            {
                E.pop_back();
                ++i;
            }
        }
        return i == lp;
    }
};
