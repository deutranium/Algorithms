def solve(n, w, v, wt):
    # Initialize DP table of size (n+1) x (w+1)
    dp = [[0] * (w + 1) for _ in range(n + 1)]
    ma = 0  # store max value found

    # Iterate through all items
    for i in range(1, n + 1):
        # Iterate through all capacities from 0 to w
        for j in range(w + 1):
            if wt[i] <= j:
                # Choose to include or exclude current item
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][max(0, j - wt[i])] + v[i])
            else:
                # Can't include item if it exceeds current capacity
                dp[i][j] = dp[i - 1][j]
            ma = max(ma, dp[i][j])  # track max so far
    
    print(f"\nMaximum value achievable: {ma}")


if __name__ == "__main__":
    # sample test case
    t = 1  # number of test cases
    test_cases = [
        {
            "n": 3,       # number of items
            "w": 4,       # total weight capacity
            "v": [0, 1, 2, 3],  # item values (1-indexed)
            "wt": [0, 4, 5, 1]  # item weights (1-indexed)
        }
    ]

    # Run all test cases
    for idx in range(t):
        case = test_cases[idx]
        print(f"Test case {idx + 1}:")
        print(f"Number of items: {case['n']}")
        print(f"Knapsack capacity: {case['w']}")
        print(f"Item values: {case['v'][1:]}")
        print(f"Item weights: {case['wt'][1:]}")
        solve(case["n"], case["w"], case["v"], case["wt"])
