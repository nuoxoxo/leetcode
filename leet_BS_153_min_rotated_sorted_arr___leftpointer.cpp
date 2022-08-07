class Solution {
public:
    int findMin(vector<int>& n)
    {
        int len, R, L, mid ;

        len = n.size();
        R = len - 1;
        L = 0;
        if (len == 1 || n[0] < n[R])
            return n[0] ;
        while (L <= R)
        {
            mid = (R - L) / 2 + L;
            if (n[mid] >= n[len - 1] && n[mid] >= n[0])
                L = mid + 1;
            else
                R = mid - 1;
        }
        return (n[L]) ;
    }
};
