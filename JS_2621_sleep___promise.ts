async function sleep(millis: number): Promise<void> {
    let promise = new Promise<void>( (resolve, reject) => {
        setTimeout(() => {
            resolve()
        }, millis)
    })
    return promise
}


/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
