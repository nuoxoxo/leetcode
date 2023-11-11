class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, vector<int>> D;
        unordered_map<int, int> idg;
        for (vector<int> & v: adjacentPairs)
        {
            int a = v[0], b = v[1];
            D[a].push_back(b);
            D[b].push_back(a);
            idg[a]++;
            idg[b]++;
        }
        vector<int> res;
        deque<int>  dq;
        int head;
        int tail;
        int head_is_found = 0;
        for (auto it: idg)
        {
            if (it.second == 1)
            {
                if (!head_is_found)
                {
                    head_is_found++;
                    head = it.first;
                    dq.push_back(head);
                }
                else
                {
                    tail = it.first;
                    break ;
                }
            }
        }
        while ( ! dq.empty())
        {
            int node = dq.front();
            dq.pop_front();
            res.push_back(node);
            for (int n: D[node])
            {
                idg[n]--;
                if (idg[n] == 1)
                    dq.push_back(n);
            }
        }
        res.push_back(tail);
        return res;
    }
};
