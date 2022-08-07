class Solution {
public:
    int coinChange(vector<int>& coins, int n)
    {
        if (!n)
            return n;

        // deque<pair<int, int>>   deck;
        // set<int>        seen;
        deque<pair<long, long>> deck;
        set<long>               seen;

        deck.push_back(make_pair(0, 0));
        while (!deck.empty())
        {
            int cur = deck[0].first;
            int lev = deck[0].second;

            if (lev && cur == n)
                return lev;
            deck.pop_front();
            for (int c : coins)
            {
                if (seen.find((long) c + cur) == seen.end() && (long) c <= n - cur)
                {
                    deck.push_back(make_pair(c + cur, lev + 1));
                    seen.insert(c + cur);
                }
            }
        }
        return -1;
    }
};
