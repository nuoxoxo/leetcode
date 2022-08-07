class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        deque<int>  E;
        int         i = 0, lp = popped.size();

        for (int p: pushed)
        {
            E.push_front(p);
            while (!E.empty() && i < lp && E.front() == popped[i])
            {
                E.pop_front();
                ++i;
            }
        }
        return i == lp;
    }
};
