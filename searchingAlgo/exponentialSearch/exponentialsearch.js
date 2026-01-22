async function exponentialSearch(a, k, display) {
    let i = 1;
    while (i<a.length && a[i]<=k) {
        i*=2;
        
        glob_comp+=2;
        refresh(glob_comp);

        display(a, undefined, 0, i);
        await sleep(glob_sleep_time);
    }

    let re = await binarySearch(a, k, Math.floor(i/2), i, display);
}