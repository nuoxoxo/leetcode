async function sleep(millis: number): Promise<void> {
    let res = new Promise<void>(
        (resolve) => {
            setTimeout(() => resolve(), millis);
        }
    );
    await res
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
