# @param {String} s
# @return {Integer}
def roman_to_int(s)
    dp = {

        #  voldemort
        V: 5,
        L: 50,
        D: 500,
        M: 1000,

        #  i x c
        I: 1,
        X: 10,
        C: 100

    }
    len = s.size
    res = 0
    i = 0
    left = 0
    right = 0
    while i < len
        left = dp[s[i].to_sym]
        right = i + 1 < len ? dp[s[i + 1].to_sym] : 0
        if left < right
            i += 1
            res += right - left
        else
            res += left
        end
        i += 1
    end
    res
end
