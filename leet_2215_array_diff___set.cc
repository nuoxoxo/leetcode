class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<int>> r{{}, {}};
        set<int>            s1;
        set<int>            s2;

        s1 = set(nums1.begin(), nums1.end());
        s2 = set(nums2.begin(), nums2.end());
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(r[0]));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(r[1]));
        return r; 
    }
};
