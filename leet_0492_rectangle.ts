function constructRectangle(area: number): number[] {
    let e = Math.floor(Math.sqrt(area))
    // console.log(e)
    while (e > 0) {
        if (area % e == 0)
            break
        e -= 1
    }
    return [area / e, e]
};
