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

    // [0,1],[1,2],[2,3],[0,2],[1,3],[2,4] -> extract a list of degress
    // 0 -> 1,2 -> degree: 2
    // 1 -> 0,2,3 -> d: 3
    // 2 -> 0,1,3,4 -> d: 4
    // 3 -> d: 2
    // 5 -> d: 1
    // [2, 3, 4, 2, 1]
    //
    //   - assign each city w/ a value 1 to n
    //   - where each value can only be used once
    //   - The importance of a road = sum of the values of the two cities it connects
    //
    // in order to get max importance, we sort the degree-list reversedly
    //   [4, 3, 2, 2, 1]
    //
    // assign value by its index plus 1
    //   4*5 + 3*4 + 2*3 + 2*2 + 1*1
    //   ^ ^   ^ ^
    //   i n   i n+1  ...
    //   res = 20+12+6+4+1 = 43 correct

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
