class Solution {
    public String longestPalindrome(String s)
    {
        int from = 0, to = 1, i = 0;
        int len = s.length();
        int L, R, dist;

        while (++i < len) {
            L = i - 1;
            R = i;
            while (R < len && L > -1 && s.charAt(L) == s.charAt(R)) {
                dist = R - L + 1;
                if (dist > to){
                    to = dist;
                    from = L;
                }
                --L;
                ++R;
            }
            L = i - 1;
            R = i + 1;
            while (R < len && L > -1 && s.charAt(L) == s.charAt(R)) {
                dist = R - L + 1;
                if (dist > to) {
                    to = dist;
                    from = L;
                }
                --L;
                ++R;
            }
        }
        if (from == to) {
            if (from * 2 == len)
                return s.substring(from);
            return s.substring(0, 1);
        }
        return s.substring(from, from + to);
    }
}
