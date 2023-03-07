function minimumTime(time: number[], totalTrips: number): number {
    let l = 0
    // console.log(Math.min(time), Math.min(...time))
    let r = Math.min(...time) * totalTrips // have to use spread operator
    while (l < r) {
        let mid = Math.floor((l + r) / 2)
        function ok(mid) {
            let trips = 0
            for (let t of time) {
                trips += Math.floor(mid / t)
            }
            return trips >= totalTrips
        }
        if (ok(mid))
            r = mid
        else
            l = mid + 1
    }
    return l
};
