class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        vector<int(*)(vector<vector<int>>&, int)> Solutions {
            median_and_flattened,
        };
        return Solutions[0](grid, x);
    }

    static int median_and_flattened(vector<vector<int>> &g, int x)
    {
        vector<int> F;
        for (auto r : g){
            for (int n : r){
                F.push_back(n);
            }
        }
        int N = F.size();
        sort(F.begin(), F.end());
        int median = F[N /2 ];
        int res = 0;
        for (int n : F) {
            int diff = abs(n - median);
            if (diff % x)
                return -1;
            res += diff / x;
        }
        return res;
    }
};
