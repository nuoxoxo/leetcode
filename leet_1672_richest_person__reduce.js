var maximumWealth = function(accounts) {
    let max = -1
    for (let acc of accounts){
        let wealth = acc.reduce((t, n) => t + n, 0)
        max = max < wealth ? wealth : max
    }
    return max
};
