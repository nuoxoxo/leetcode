class Solution {
public:
    int maxUniqueSplit(string s)
    {
        vector<std::function<int(string)>> solutions = {
            Backtracking,
        };
        return solutions[0]( s );

    }

    static int Backtracking(string s) {
        int N = s.size();
        set<string> SEEN;
        std::function<int(int)> backtrack = [&](int L){
            if (L == N)
                return 0;
            int R = L - 1;
            int res = 0;
            while (++R < N)
            {
                string sub = s.substr(L, R - L + 1);
                if (SEEN.find(sub) != SEEN.end())
                    continue ;
                SEEN.insert(sub);
                res = max(res, backtrack(R + 1) + 1);
                SEEN.erase(sub);
            }
            return res;
        };
        return backtrack( 0 );
    }

};


