// Name: Kdane's Algorithm in C#
// Function: Finds the subarray with the maximum sum for an array of numbers
// Time Complexity: O(n)
// Space Complexity: O(1)

static int kdanesAlgorithm(int[] array)
{
    // Store the highest sum encountered thus far and the current sum
    int maxSum = Int32.MinValue;
    int currentSum = 0;

    for (int i = 0; i < array.Length; i++)
    {
        // Decide whether to (largest is picked):
        // (1) Extend the existing subarray (currentSum + array[i])
        // (2) Start a new subarray from the current element (array[i])
        currentSum = Math.Max(array[i], currentSum + array[i]);

        // Update maxSum if the currentSum exceeds it
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

// MAIN(), using Top-Level Statements

// Test Case 1: Mix of positive and negative numbers
// Expected Output: 6
int[] test1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
Console.WriteLine("Test 1 (Mixed Numbers): " + KdanesAlgorithm(test1));

// Test Case 2: All negative numbers
// Expected Output: -1
int[] test2 = { -5, -2, -3, -7, -1 };
Console.WriteLine("Test 2 (All Negatives): " + KdanesAlgorithm(test2));

// Test Case 3: All positive numbers
// Expected Output: 15
int[] test3 = { 2, 3, 1, 5, 4 };
Console.WriteLine("Test 3 (All Positives): " + KdanesAlgorithm(test3));
