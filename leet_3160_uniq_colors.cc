class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int,int> D, colors;
        int curr = 0, N = queries.size();
        vector<int> res(N, 0);
        int i = -1;
        while (++i < N) {
            int x = queries[i][0], y = queries[i][1];
            int oc = D[x];
            if (colors[oc] > 0) {
                colors[oc]--;
                if (!colors[oc])
                    curr--;
            }
            if (!colors[y])
                curr++;
            res[i] = curr;
            colors[y]++;
            D[x] = y;
        }
        return res;
    }
};
