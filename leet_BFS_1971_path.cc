class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int des)
    {
        vector<int> total[n];
        deque<int>  dq;
        bool        v[n];
        int         i, m;

        memset(v, false, sizeof(v));
        m = (int) edges.size();
        i = -1;
        while (++i < m)
        {
            total[edges[i][0]].push_back(edges[i][1]);
            total[edges[i][1]].push_back(edges[i][0]);
        }
        dq.push_back(src);
        while(!dq.empty())
        {
            int p;
            
            p = dq.front();
            dq.pop_front();
            if (p == des)
                return true;
            i = -1;
            while (++i < (int) total[p].size())
            {
                if (!v[total[p][i]])
                {
                    dq.push_back(total[p][i]);
                    v[total[p][i]] = true;
                }
            }
        }
        return false;
    }
};
