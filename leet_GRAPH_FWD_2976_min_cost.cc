class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        vector<long long(*)(string, string, 
            vector<char>&, vector<char>&, vector<int>&)> Solutions = {
            // Floyd_Warshall_DP,
            Dijkstra,
        };
        return Solutions[0]( source, target, original, changed, cost );
    }

    static long long Dijkstra(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {

        #define ll long long

        unordered_map<int, vector<pair<ll, int>>> W;
        int len = original.size();
        int i = -1;
        while (++i < len)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int c = cost[i];
            W[u].push_back( {c, v} );
        }

        function<ll(int, int)> dijkstra = [&](int src, int des) {
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> heap;
            heap.push({0, src});
            vector<ll> weights(26, LLONG_MAX);
            set<int> SEEN;
            while (!heap.empty())
            {
                auto p = heap.top();
                heap.pop();
                ll curr_cost = p.first;
                int curr_node = p.second;
                if (curr_node == des)
                    return curr_cost;
                if (SEEN.find(curr_node) == end(SEEN))
                {
                    SEEN.insert(curr_node);
                    for (auto & _next : W[curr_node])
                    {
                        ll next_cost = _next.first;
                        int next_node = _next.second;
                        ll tt_cost = curr_cost + next_cost;
                        if (tt_cost < weights[next_node])
                        {
                            weights[next_node] = tt_cost;
                            heap.push( {tt_cost, next_node} );
                        }
                    }
                }
            }
            return LLONG_MAX;
        };


        ll res = 0;
        vector<vector<bool>> has_cache(26, vector<bool>(26, false));
        vector<vector< ll >> cache(26, vector< ll >(26, 42));
        i = -1;
        int N = source.size();
        while (++i < N)
        {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v)
                continue ;
            if (has_cache[u][v])
            {
                res += cache[u][v];
            }
            else
            {
                ll c = dijkstra(u, v);
                if (c == LLONG_MAX)
                    return -1;
                has_cache[u][v] = true;
                cache[u][v] = c;
                res += c;
            }
        }
        return res;
    }

    static int idx(int n) { return n - 'a'; }

    static long long Floyd_Warshall_DP(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        vector<vector<long long>> W( 26, vector<long long>(26, LLONG_MAX) );
        int N = cost.size();
        int i = -1, u, v, c;
        while (++i < N)
        {
            u = idx(original[i]);
            v = idx(changed[i]);
            c = cost[i];
            if (W[u][v] > c)
                W[u][v] = c;
        }
        int inter = -1;
        while (++inter < 26)
        {
            u = -1;
            while (++u < 26)
            {
                v = -1;
                while (++v < 26)
                {
                    if (W[u][inter] == LLONG_MAX || W[inter][v] == LLONG_MAX)
                        continue ;
                    unsigned long long temp = W[u][inter] + W[inter][v];
                    if (temp > LLONG_MAX)
                        continue ;
                    (long long) temp;
                    W[u][v] > temp ? W[u][v] = temp : W[u][v];
                }
                    
            }
        }
        long long res = 0;
        N = source.size();
        i = -1;
        while (++i < N)
        {
            u = idx(source[i]);
            v = idx(target[i]);
            if (u == v)
                continue ;
            if (W[u][v] == LLONG_MAX)
                return -1;
            res += W[u][v];
        }
        return res;
    }


};
