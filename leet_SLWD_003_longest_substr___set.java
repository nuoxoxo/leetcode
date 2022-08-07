class Solution {
    public int lengthOfLongestSubstring(String s)
    {
        int len = s.length();
        if (len < 2)
            return len;
        Set<Character>  E = new HashSet<>();
        int             res = 0, L = 0, R = -1;
        while (++R < len)
        {
            while (E.contains(s.charAt(R)))
            {
                E.remove(s.charAt(L));
                ++L;
            }
            E.add(s.charAt(R));
            res = Math.max(res, R - L + 1);
        }
        return res;
    }
}
