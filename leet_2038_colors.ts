function winnerOfGame(colors: string): boolean {
    if (colors.length < 3)
        return false
    let [a, b] = [0, 0]
    let i = 0
    while (++i < colors.length - 1) {
        if (colors[i - 1] === colors[i] && colors[i] === colors[i + 1]) {
            if (colors[i] === 'A')
                ++a
            else
                ++b
        }
    }
    return a > b
};
