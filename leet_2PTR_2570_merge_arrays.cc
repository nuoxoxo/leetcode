class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while (i < len1 && j < len2) {
            int a,b,c,d;
            a = nums1[i][0], b = nums1[i][1], c = nums2[j][0], d = nums2[j][1];
            if (a == c && ++i && ++j)
                res.push_back({ a, b + d });
            else if (a < c && ++i) 
                res.push_back({ a, b });
            else if (a > c && ++j)
                res.push_back({ c, d });
        }
        while (i < len1)
            res.push_back(nums1[i++]);
        while (j < len2)
            res.push_back(nums2[j++]);
        return res;
    }
};
