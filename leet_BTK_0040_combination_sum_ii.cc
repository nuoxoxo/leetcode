class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<vector<int>>(*)(vector<int> &, int)> solutions {
            Backtracking,
        };
        return solutions[0](candidates, target);
    }

    static vector<vector<int>> Backtracking(vector<int>& C, int T)
    {
        sort(begin(C), end(C));
        int N = C.size();
        vector<int> temp;
        vector<vector<int>> res;
        std::function<void(int, int, int, vector<vector<int>> &, vector<int> &, vector<int> &)> BT;
        BT = [&](int idx, int N, int T, vector<vector<int>> & res, vector<int> & temp, vector<int> & C)
        {
            if (!T)
            {
                res.push_back(temp);
                return ;
            }
            if (idx == N)
            {
                return ;
            }
            int L = idx;
            while (idx < N)
            {
                if (idx && idx ^ L && C[idx] == C[idx - 1])
                {
                    ++idx;
                    continue ;
                }
                if (C[idx] <= T)
                {
                    temp.push_back(C[idx]);
                    BT(idx + 1, N, T - C[idx], res, temp, C);
                    temp.pop_back();
                }
                else
                {
                    break ;
                }
                idx++;
            }
        };
        BT(0, N, T, res, temp, C);
        return res;
    }
};
