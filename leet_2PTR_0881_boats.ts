function numRescueBoats(people: number[], limit: number): number {
    let i = 0
    let j = people.length - 1
    let boats = 0
    people.sort((a, b) => a - b)
    while (i <= j) {
        ++boats
        if (people[i] + people[j] <= limit) {
            ++i
        }
        --j
    }
    return boats
};
