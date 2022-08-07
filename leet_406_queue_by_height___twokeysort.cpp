class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        vector<vector<int>> res;
        int len = (int) people.size();
        int i = -1;

        sort(people.begin(), people.end(), cmp);
        while (++i < len)
        {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b)
    {
        if (a[0] > b[0])    return true;
        if (a[0] == b[0])   return a[1] < b[1];
        return false;
    }
};
