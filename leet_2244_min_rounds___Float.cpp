class Solution {
public:
    int minimumRounds(vector<int>& tasks)
    {
        int res = 0;
        unordered_map<int, int> E;
        unordered_map<int, int>::iterator it;
        for (int & n: tasks)
            ++E[n];
        it = E.begin();
        while (it != E.end())
        {
            int n = it->second;
            if (n == 1)
                return -1;
            if (n == 2)
                ++res;
            else if (n > 2)
                res += ceil((float) n / 3);
            ++it;
        }
        return res;
    }
};
