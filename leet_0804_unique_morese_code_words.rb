# @param {String[]} words
# @return {Integer}

def unique_morse_representations(words)
    alphabet = ('a'..'z').to_a
    set = []
    words.each do |w|
        set << matching(w, alphabet)
    end
    set.uniq.length
end

def matching(w, alphabet)
    morsecode = [
        ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.",
        "---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."
    ]
    res = ""
    w.split('').each do |c|
        res += morsecode[alphabet.index(c)]
    end
    res
end


=begin

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
=end
