function fib(n) {
    if (n <= 0)
        return 0;
    if (n <= 2)
        return 1;
    return fib(n-1) + fib(n-2);
}

function smallest_greater_eq_fib(n) {
    let f = fib(0),
        cu = 0;
    while (f < n)
        f = fib(++cu);

    return cu;
}

async function fibonacciSearch(a, k, l, r, display) {
    let f = smallest_greater_eq_fib(r-l+1);

    while (f >= 0) {
        i = Math.min(l+fib(f-1), r-1);
        i = Math.max(0, i);

        refresh(glob_comp, a[i]);

        display(a, i, l, r);
        await sleep(glob_sleep_time);

        if (a[i]==k) {
            glob_comp++;
            refresh(glob_comp, a[i]);

            return new Promise(resolve => resolve(i));
        } else if (k < a[l+fib(f-1)]) {
            glob_comp+=2;
            refresh(glob_comp, a[i]);

            r = i;
            f-=1;
        } else {
            glob_comp+=2;
            refresh(glob_comp, a[i]);

            l = i;
            f-=2;
        }
    }

    return new Promise(resolve => resolve(-1));
}