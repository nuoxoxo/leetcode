function average(salary: number[]): number {
    // way 1
    /*
    let lo = Math.min(...salary), hi = Math.max(...salary)
    let arr = []
    for (let n of salary) {
        if (n ^ lo && n ^ hi) {
            arr.push(n)
        }
    }
    return arr.reduce((a, b) => a + b) / (salary.length - 2)
    */

    // way 2
    return (salary.reduce((a, b) => a + b) - Math.min(...salary) - Math.max(...salary)) / (salary.length - 2)
};
