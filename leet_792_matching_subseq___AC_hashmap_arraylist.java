class Solution {
    public int numMatchingSubseq(String s, String[] words)
    {
        Map<String, Integer>    seen = new HashMap<String, Integer>();
        ArrayList<String>       copy = new ArrayList<String>();
        int                     res, lw, ls, i, j;

        res = 0;
        for (String w : words)
        {
            if (!seen.containsKey(w))
            {
                seen.put(w, 1);
            }
            else
            {
                seen.replace(w, seen.get(w) + 1);
            }
        }
        // System.out.println(seen.toString()); // test
        // words = new String[0]; // doesn't work like this
        for (String key : seen.keySet())
        {
            copy.add(key);
        }
        res = 0;
        ls = s.length();
        for (String w: copy)
        {
            lw = w.length();
            i = 0;
            j = 0;
            while (i < ls && j < lw)
            {
                if (s.charAt(i) == w.charAt(j))
                    ++j;
                ++i;
            }
            if (j == lw)
            {
                res += seen.get(w);
            }
        }
        return res;
    }
}
