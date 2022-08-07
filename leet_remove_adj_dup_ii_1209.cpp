class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        deque<pair<char, int>>  dq;
        for (char c: s)
        {
            
            if (!dq.empty() && c == dq.back().first)
            {
                if (dq.back().second == k - 1)
                    dq.pop_back();
                else
                    ++dq.back().second;
            }
            else
                dq.push_back(make_pair(c, 1));
        }
        string  res;
        while (!dq.empty())
        {
            while (--dq.front().second > -1)
                res += dq.front().first;
            dq.pop_front();
        }
        return res;
    }
};
