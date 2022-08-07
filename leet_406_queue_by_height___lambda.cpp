class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p)
    {
        sort(p.begin(), p.end(), [](vector<int>& a, vector<int>& b)
             {
                 if (a[0] > b[0])   return true;
                 if (a[0] == b[0])  return a[1] < b[1];
                 return false;
             });
        vector<vector<int>> res;
        for (vector<int> n: p)
        {
            res.insert(res.begin() + n[1], n);
        }
        return res;
    }
};
