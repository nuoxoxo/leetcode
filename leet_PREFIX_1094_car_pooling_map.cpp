class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int seats)
    {
        map<int, int>   E;
        int             i, j;

        i = -1;
        while (++i < trips.size())
        {
            j = trips[i][1] - 1;
            while (++j < trips[i][2])
                E[j] += trips[i][0];
        }

        map<int, int>::iterator it = E.begin();
        while (it != E.end())
        {
            if (it->second > seats)
                return false ;
            it ++;
        }
        return true ;
    }
};
