class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        map<int, int>           players;
        map<int, int>::iterator it;
        vector<int>             winall;
        vector<int>             lose1;

        for (vector<int>& m : matches)
        {
            /*
            if (players.find(m[0]) == players.end())
                players[m[0]] = 0;
            if (players.find(m[1]) == players.end())
                players[m[1]] = 1;
            else
                players[m[1]]++;
            */

            // no find(), faster

            players[m[0]] += 0;
            players[m[1]] += 1;
        }
        it = players.begin();
        while (it != players.end())
        {
            if (it->second == 0)
                winall.push_back(it->first);
            if (it->second == 1)
                lose1.push_back(it->first);
            ++it;
        }
        sort(winall.begin(), winall.end());
        sort(lose1.begin(), lose1.end());
        return {winall, lose1};
    }
};
