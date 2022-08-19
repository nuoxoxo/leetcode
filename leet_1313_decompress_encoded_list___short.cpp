class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums)
    {
        vector<vector<int>> temp;
        vector<int> res;
        int i = 0, len = 0;

        while (i < nums.size())
        {
            len += nums[i];
            i += 2;
        }
        res.reserve(len);
        i = 0;
        while (i < nums.size())
        {
            vector<int> t;
            int j = -1;

            while (++j < nums[i])
                t.push_back(nums[i + 1]);
            temp.push_back(t);
            i += 2;
        }
        for (vector<int> t : temp)
        {
            for (int n : t)
                res.push_back(n);
        }
        return res;
    }
};
