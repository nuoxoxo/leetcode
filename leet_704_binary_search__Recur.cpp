/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int mid = n / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            return recurse(nums, target, 0, mid - 1);
        return recurse(nums, target, mid + 1, n - 1);
    }
    
    int recurse(vector<int>& n, int t, int L, int R)
    {
        if (L > R)
            return -1;
        int m = (R - L) / 2 + L;
        if (n[m] > t)
            return recurse(n, t, L, m - 1);
        if (n[m] < t)
            return recurse(n, t, m + 1, R);
        return m;
    }
};
