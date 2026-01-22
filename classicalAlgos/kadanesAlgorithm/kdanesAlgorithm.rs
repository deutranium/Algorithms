// Name: Kdane's Algorithm in Rust
// Function: Finds the subarray with the maximum sum for an array of numbers
// Time Complexity: O(n)
// Space Complexity: O(1)

use std::cmp;

// Function takes an immutable reference to an array as mutability/ownership is not needed
fn kdanesAlgorithm(array: &[i32]) -> i32 {
    // Store the highest sum encountered thus far and the current sum
    let mut maxSum = i32::MIN;
    let mut currentSum = 0;

    for currentElement in array.iter() {
        // Decide whether to (largest is picked):
        // (1) Extend the existing subarray (currentSum + array[i])
        // (2) Start a new subarray from the current element (array[i])

        // Use .clone() to retain ownership of currentSum
        currentSum = cmp::max(currentSum.clone() + currentElement, currentElement.clone());

        // Update maxSum if the currentSum exceeds it
        if currentSum > maxSum {
            maxSum = currentSum;
        }
    }
    // Return maxSum
    maxSum
}

fn main() {
    // Test Case 1: Mixed positive and negative numbers
    // Expected Output: 6
    let test1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
    println!("Test 1 (Mixed Numbers): {}", kdanesAlgorithm(&test1));

    // Test Case 2: All negative numbers
    // Expected Output: -1
    let test2 = [-5, -2, -3, -7, -1];
    println!("Test 2 (All Negatives): {}", kdanesAlgorithm(&test2));

    // Test Case 3: All positive numbers
    // Expected Output: 15
    let test3 = [2, 3, 1, 5, 4];
    println!("Test 3 (All Positives): {}", kdanesAlgorithm(&test3));
}

