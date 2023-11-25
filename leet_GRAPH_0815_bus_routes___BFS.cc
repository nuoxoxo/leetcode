class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        if (source == target)
            return 0;

        // adj represents - a stop : all routes that incl. this stop 
        unordered_map<int, vector<int>> adj;
        // for (vector<int> & stops: routes)
        int i = -1;
        while (++i < (int) routes.size())
        {
            for (int & stop: routes[i])
                adj[stop].push_back(i);
        }

        //  deque for BFS
        deque<int>  dq;
        //  keeping track of seen routes
        unordered_set<int>  seen;
        //  prepare the begining node for BFS

        for (int & route : adj[source])
        {
            dq.push_back(route);
            seen.insert(route);
        }

        //  BFS proper
        int res = 1;
        while ( ! dq.empty())
        {
            int len = (int) dq.size();
            int i = -1;
            while (++i < len)
            {
                int current_stop = dq.front();
                dq.pop_front();
                for (int stop : routes[current_stop])
                {
                    if (stop == target)
                        return res;
                    for (int & next: adj[stop])
                    {
                        if (!seen.count(next))
                        {
                            seen.insert(next);
                            dq.push_back(next);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
