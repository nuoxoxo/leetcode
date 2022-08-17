func uniqueMorseRepresentations(words []string) int {
    set := make(map [string] bool)
    for _, w := range words {
        set[matching(w)] = true
    }
    return len(set)
}

func matching(s string) string {
    morsecode := [] string {
        ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.",
        "---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."}
    res := ""
    for _, c := range s {
        res += morsecode[c - 'a']
    }
    return res
}


/*

a-z mapping:

".-",
"-...",
"-.-.",
"-..",
".",
"..-.",
"--.",
"....",
"..",
".---",
"-.-",
".-..",
"--",
"-.",
"---",
".--.",
"--.-",
".-.",
"...",
"-",
"..-",
"...-",
".--",
"-..-",
"-.--",
"--.."
*/
