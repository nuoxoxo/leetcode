/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

var convert = function(s, numRows) {
    if (numRows < 2)
        return s;
    arr = new Array(numRows).fill('')
    n = s.length;
    res = '';
    i = -1;
    r = 0;
    while (++i < n)
    {
        arr[r] += s[i];

        // console.log(arr[r])

        c = Math.floor(i / (numRows - 1));
        if (c % 2 == 0)
            ++r;
        else
            --r;
    }
    for (let tmp of arr) {
        res += tmp;
    }
    return res;
};
