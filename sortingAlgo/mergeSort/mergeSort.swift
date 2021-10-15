// a function that merges two arrys
func merge(_ array_1: inout [Int], _ low: Int, _ mid: Int, _ high: Int) {
    var i = low
    var j = mid + 1
    var k = 0
    
    var array_2: [Int] = [Int](repeating: 0, count: high - low + 1)
    
    while i <= mid && j <= high {
        if array_1[i] <= array_1[j] {
            array_2[k] = array_1[i]
            k += 1
            i += 1
        }
        else {
            array_2[k] = array_1[j]
            k += 1
            j += 1
        }
    }
    
    while i <= mid {
        array_2[k] = array_1[i]
        k += 1
        i += 1
    }
    
    while j <= high {
        array_2[k] = array_1[j]
        k += 1
        j += 1
    }
    
    for i in low...high {
        array_1[i] = array_2[i - low]
    }
}

// the recursive sorting algorithm that divides the array, sorts the two halves and merges them
func sort(_ array: inout [Int], _ low: Int, _ high: Int) {
    if low < high {
        let mid = (low + high) / 2
        sort(&array, low, mid)
        sort(&array, mid + 1, high)
        merge(&array, low, mid, high)
    }
}
