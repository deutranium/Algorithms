fn main() {
    // Testcase
    let arr = ["a", "b", "c", "d"];
    let x = "b";
    let result = linear_search(&arr, x);
    
    if result == -1 {
        println!("Element is not present in array");
    } else {
        println!("Element is present at index {}", result);
    }
}

fn linear_search(arr: &[&str], x: &str) -> isize {
    for (i, val) in arr.into_iter().enumerate() {
        if *val == x {
            return i as isize;
        }
    }

    -1
}