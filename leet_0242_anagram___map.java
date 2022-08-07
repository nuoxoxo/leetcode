class Solution {
    public boolean isAnagram(String s, String t)
    {
        int[]   map;
        int     len, i;

        len = s.length();
        if (len != t.length())
            return false;
        map = new int[26];
        i = -1;
        while (++i < len)
        {
            ++map[s.charAt(i) - 'a'];
            --map[t.charAt(i) - 'a'];
        }
        i = -1;
        while (++i < 26 && map[i] == 0)
            ;
        if (i == 26)
            return true;
        System.out.println("hi\n");
        return false;
    }
}
