class Solution {
public:
    vector<int> lexicalOrder(int n)
    {
        vector<vector<int>(*)(int)> Solutions = {
            // DFS,
            Iterative, // faster
        };
        return Solutions[0](n);
    }

    static vector<int> Iterative(int n)
    {
        vector<int> res;
        int curr = 1;
        int i = -1;
        while (++i < n)
        {
            res.push_back(curr);
            if (curr <= n)
                curr = curr * 10;
            if (curr > n)
            {
                curr = curr / 10;
                if (curr == n)
                    curr = curr / 10;
                curr += 1;
                while (curr % 10 == 0)
                    curr = curr / 10;
            }
        }
        return res;
    }

    static vector<int> DFS(int n)
    {
        int N = min(10, n + 1);
        vector<int> res;

        std::function<void(int curr)> dfs = [&](int curr)
        {
            if (curr > n) return ;
            res.push_back(curr);
            int i = -1;
            
            while (++i < N)
                dfs (curr * 10 + i);
        };

        int curr = 0;
        while (++curr < N)
            dfs(curr);
        return res;
    }

};
