class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2)
    {
        // String[]    res; /* you need List<String> */
        List<String>    res;
        int             freq[];
        int             len1, len2, i;

        res = new ArrayList<String>();
        len1 = words1.length;
        len2 = words2.length;
        freq = new int [26];
        Arrays.fill(freq, 0);
        for (String s: words2)
        {
            int     temp[] = new int [26];

            Arrays.fill(temp, 0);
            for (char c: s)
            {
                temp[c - 'a']++;
                freq[c - 'a'] = max(freq[c - 'a'], temp[c - 'a']);
            }
        }
        for (String s: words1)
        {
            int     temp[] = new int [26];

            Arrays.fill(temp, 0);
            for (char c: s)
                temp[c - 'a']++;
            i = -1;
            while (++i < 26 && temp[i] >= freq[i])
                ;
            if (i == 26)
                res.add(s);
        }
    }
}
