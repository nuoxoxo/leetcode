/**
 * @param {string[]} words
 * @return {number}
 */

var uniqueMorseRepresentations = function(words) {
    let E = new Set()
    for (let s of words) {
        E.add(matching(s))
    }
    return E.size
};

var matching = function(word) {
    let morse = [".-","-...","-.-.","-..",".","..-.","--.",
                 "....","..",".---","-.-",".-..","--","-.",
                 "---",".--.","--.-",".-.","...","-","..-",
                 "...-",".--","-..-","-.--","--.."]
    let s = ""
    let a = 'a'.charCodeAt(0)
    for (let c of word) {
        s += morse[c.charCodeAt(0) - a]
    }
    return s
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
