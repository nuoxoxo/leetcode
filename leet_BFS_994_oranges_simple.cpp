/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int                     generation, i, j, x, y;
        vector<pair<int, int>>  rotten;
        vector<pair<int, int>>  fresh;
        vector<pair<int, int>>  dir;

        i = -1;
        dir= {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while (++i < grid.size())
        {
            j = -1;
            while (++j < grid[i].size())
            {
                if ( grid[i][j] == 1 )  fresh.push_back({i, j});
                if ( grid[i][j] == 2 )  rotten.push_back({i, j});
            }
        }
        if (!rotten.size() && fresh.size()) return (-1);
        if (!fresh.size())                  return (0);
        generation = 0;
        while (fresh.size() > 0)
        {
            vector<pair<int, int>>  infected;
            i = -1;
            while (++i < rotten.size())
            {
                x = rotten[i].first;
                y = rotten[i].second;
                j = -1;
                while (++j < dir.size())
                {
                    pair<int, int>                      temp;
                    vector<pair<int, int>>::iterator    it;

                    temp = { x + dir[j].first, y + dir[j].second };
                    it = find(fresh.begin(), fresh.end(), temp);
                    if (it != fresh.end())
                    {
                        fresh.erase(it);
                        it = find(infected.begin(), infected.end(), temp);
                        if ( it == infected.end() ) infected.push_back(temp);
                    }
                }
            }
            if ( !infected.size() ) return (-1);
            rotten = infected;
            generation++;
        }
        return (generation);
    }
};

