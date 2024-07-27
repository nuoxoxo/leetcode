class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost)
    {
        vector<long long(*)(string, string, vector<char>&, vector<char>&, vector<int>&)> Solutions = {
            Floyd_Warshall_DP,
        };
        return Solutions[0]( source, target, original, changed, cost );
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
