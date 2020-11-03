struct Heap<T> {
    array: [T; 32],
    is_minheap: bool,
    size: usize,
}

impl<T> Heap<T>
where
    T: PartialOrd + Copy + Default,
{
    fn new() -> Self {
        Heap {
            array: [T::default(); 32],
            is_minheap: false,
            size: 0,
        }
    }

    fn insert(&mut self, k: T) {
        self.size += 1;
        self.array[self.size] = k;
        let mut i = self.size;

        while i > 1 && self.compare(i >> 1, i) {
            let temp = self.array[i];
            self.array[i] = self.array[i >> 1];
            self.array[i >> 1] = temp;
            i >>= 1;
        }
    }

    fn heapify(&mut self, i: usize) {
        let l = i << 1;
        let r = l | 1;

        let mut max = i;
        if l <= self.size && !self.compare(l, max) {
            max = l;
        }
        if r <= self.size && !self.compare(r, max) {
            max = r;
        }

        if max != i {
            let temp = self.array[i];
            self.array[i] = self.array[max];
            self.array[max] = temp;
            self.heapify(max);
        }
    }

    fn extract(&mut self) -> T {
        let temp = self.array[1];
        self.array[1] = self.array[self.size];
        self.array[self.size] = temp;
        self.size -= 1;

        self.heapify(1);

        self.array[self.size + 1]
    }

    fn compare(&self, x: usize, y: usize) -> bool {
        match self.is_minheap {
            false => self.array[x] < self.array[y],
            true => self.array[x] > self.array[y],
        }
    }
}

fn build<T: PartialOrd + Copy + Default>(array: [T; 32], n: usize) -> Heap<T> {
    let mut heap = Heap::<T>::new();

    heap.size = n;
    heap.array = array;

    for i in (1..=n / 2).rev() {
        heap.heapify(i);
    }

    heap
}

fn heapsort<T: PartialOrd + Copy + Default>(array: [T; 32], n: usize) -> [T; 32] {
    let mut heap = build(array, n);
    let mut arr: [T; 32] = [T::default(); 32];
    for i in (0..n).rev() {
        arr[i] = heap.extract();
    }

    arr
}

fn main() {
    let mut h = Heap::<i32>::new();
    println!("{:?}", h.array);
    h.insert(5);
    h.insert(24);
    h.insert(1);
    h.insert(12);
    println!("{:?}\n", h.array);

    let mut arr: [i32; 32] = [0; 32];
    arr[1] = 5;
    arr[2] = 24;
    arr[3] = 1;
    arr[4] = 12;
    println!("{:?}", &arr);
    let hh = heapsort(arr, 4);
    println!("{:?}", hh);
}
