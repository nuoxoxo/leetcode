class Solution {
    public int uniqueMorseRepresentations(String[] words)
    {
        Set<String>     strset = new HashSet<>();

        for (String w : words)
            strset.add(matching(w));
        return strset.size();
    }

    public String matching(String s)
    {
        String          res;
        String[]        morsecode = {
                ".-","-...","-.-.","-..",".","..-.","--.",
                "....","..",".---","-.-",".-..","--","-.",
                "---",".--.","--.-",".-.","...","-","..-",
                "...-",".--","-..-","-.--","--.."
            };

        res = "";
        for (char c: s.toCharArray())
            res += morsecode[c - 'a'];
        return res;
    }
}
