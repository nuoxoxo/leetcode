class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> res;
        for (vector<int> & r: image)
        {
            vector<int> tmp;
            reverse(r.begin(), r.end());
            for (int & n: r)
                tmp.push_back(n ? 0 : 1);
            res.push_back(tmp);
        }
        return res;
    }
};
