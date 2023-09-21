class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> N;
        N.insert(N.begin(), nums1.begin(), nums1.end());
        N.insert(N.begin(), nums2.begin(), nums2.end());
        sort(N.begin(), N.end());
        int len = N.size();
        int mid = len / 2;
        if (len % 2)
            return N[mid];
        return (double) (N[mid - 1] + N[mid]) / 2;
    }
};

