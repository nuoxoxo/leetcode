var multiply = function(num1, num2) {
    if(Number.isNaN(num1) || Number.isNaN(num2))
        return ''
    if (num1 == '0' || num2 == '0')
        return '0'
    let len1 = num1.length, len2 = num2.length
    let ans = []

    for (let i = len1 - 1; i >= 0; i--) {
        for (let j = len2 - 1; j >= 0; j--) {
            let index1 = i + j, index2 = i + j + 1
            let mul = num1[i] * num2[j] + (ans[index2] || 0)
            ans[index1] = Math.floor(mul / 10) + (ans[index1] || 0)
            ans[index2] = mul % 10
        }
    }
    let result = ans.join('').replace(/^0+/,'')
    return (result)
};

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
