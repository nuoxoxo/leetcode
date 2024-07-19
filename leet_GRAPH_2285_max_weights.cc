class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<long long(*)(int, vector<vector<int>> &)> Solutions = {
            // way1,
            way2reverseSort,
        };
        return Solutions[0](n, roads);
    }

    static long long way2reverseSort(int n, vector<vector<int>> & roads)
    {
        vector<long long> importance(n, 0);
        for (vector<int> & p : roads)
        {
            int c1 = p[0], c2 = p[1];
            importance[ c1 ] ++;
            importance[ c2 ] ++;
        }
        sort(begin(importance), end(importance), greater<int>());
        long long res = 0;
        int i = -1;
        while (++i < n)
            res += (n - i) * importance[i];
        return res;
    }

    static long long way1(int n, vector<vector<int>> & roads)
    {
        vector<long long> importance(n, 0);
        for (vector<int> & p : roads)
        {
            int c1 = p[0], c2 = p[1];
            importance[ c1 ] ++;
            importance[ c2 ] ++;
        }
        sort(begin(importance), end(importance));
        long long res = 0;
        int i = -1;
        while (++i < n)
            res += (i + 1) * importance[i];
        return res;
    }
};
