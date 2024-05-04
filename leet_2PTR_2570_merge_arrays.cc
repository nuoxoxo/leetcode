class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        vector<vector<int>> res;
        int i, j;
        i = j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (i < len1 && j < len2)
        {
            int a = nums1[i][0], b = nums1[i][1];
            int c = nums2[j][0], d = nums2[j][1];
            if (a == c)
            {
                res.push_back({ a, b + d });
                ++i;
                ++j;
            }
            else if (a < c)
            {
                res.push_back({ a, b });
                ++i;
            }
            else if (a > c)
            {
                res.push_back({ c, d });
                ++j;
            }
        }
        while (i < len1)
        {
            int a = nums1[i][0], b = nums1[i][1];
            res.push_back({nums1[i][0], nums1[i][1]});
            ++i;
        }
        while (j < len2)
        {
            int a = nums2[j][0], b = nums2[j][1];
            res.push_back({nums2[j][0], nums2[j][1]});
            ++j;
        }
        return res;
    }
};
