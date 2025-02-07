class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int,int> D, colors;
        int curr = 0;
        vector<int> res;
        for (auto q: queries){
            int x = q[0], y = q[1];
            int oc = D[x];
            if (colors[oc] > 0) {
                colors[oc]--;
                if (!colors[oc])
                    curr--;
            }
            if (!colors[y])
                curr++;
            res.push_back(curr);
            colors[y]++;
            D[x] = y;
        }
        return res;
    }
};
