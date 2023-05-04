class Solution {
public:
    string predictPartyVictory(string senate)
    {
        std::deque<int> R, D;
        int     i = -1;
        while (++i < senate.length())
        {
            char    c = senate[i];
            if (c == 'R')
                R.push_back(i);
            else
                D.push_back(i);
        }
        while (R.size() && D.size())
        {
            int r = R.front(), d = D.front();
            R.pop_front();
            D.pop_front();
            if (r < d)
            {
                R.push_back(i++);
            }
            else
            {
                D.push_back(i++);
            }
        }
        return R.size() ? "Radiant" : "Dire";
    }
};
