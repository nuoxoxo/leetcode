class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> joined;
        joined.insert(joined.begin(), nums1.begin(), nums1.end());
        joined.insert(joined.begin(), nums2.begin(), nums2.end());
        sort(joined.begin(), joined.end());
        int len = joined.size();
        int mid = len / 2;
        if (len % 2)
            return joined[mid];
        return (float) (joined[mid - 1] + joined[mid]) / 2;
    }
};
