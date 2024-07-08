class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<int(*)(string, string)> Solutions = {
            // dfs,
            bfs,
        };
        return Solutions[0](word1, word2);
    }

    static int bfs (string w1, string w2)
    {
        int n1 = w1.length();
        int n2 = w2.length();
        deque<vector<int>> Q{ {0, 0} };
        set<vector<int>> SEEN;
        int res = 0;
        while (!Q.empty())
        {
            int N = Q.size();
            int i = -1;
            while (++i < N)
            {
                auto top = Q.front();
                Q.pop_front();
                int l = top[0], r = top[1];
                if (SEEN.find({l, r}) != end(SEEN))
                    continue ;
                
                while (l < n1 && r < n2 && w1[l] == w2[r])
                {
                    ++l;
                    ++r;
                }
                if (l == n1 && r == n2)
                    return res;

                vector<int> p;

                // INSERT
                p = {l, r + 1};
                if (SEEN.find(p) == end(SEEN))
                    Q.push_back(p);
                // REPLACE
                p = {l + 1, r + 1};
                if (SEEN.find(p) == end(SEEN))
                    Q.push_back(p);
                // DELETE
                p = {l + 1, r};
                if (SEEN.find(p) == end(SEEN))
                    Q.push_back(p);
                SEEN.insert( {l, r} );
            }
            res++;
        }
        assert (false);
        return -1;
    }

    static int dfs (string w1, string w2)
    {
        int n1 = w1.length();
        int n2 = w2.length();
        vector<vector<bool>> cached( n1 + 1, vector<bool>(n2 + 1, false) );
        vector<vector<int>> caching( n1 + 1, vector<int>(n2 + 1, -1) );
        function<int(int, int)> f/*(int, int)*/ = [&](int l, int r) -> int {
            if (l == n1)
                return n2 - r;
            if (r == n2)
                return n1 - l;
            if (cached[l][r])
                return caching[l][r];
            int res = INT_MAX;
            int temp;
            if (w1[l] == w2[r])
                res = min(f(l + 1, r + 1), res);
            // INSERT
            res = min(f(l, r + 1) + 1, res);
            // DELETE
            res = min(f(l + 1, r) + 1, res);
            // REPLACE
            res = min(f(l + 1, r + 1) + 1, res);
            cached[l][r] = true;
            caching[l][r] = res;
            return res;
        };
        return f (0, 0);
    }
};
