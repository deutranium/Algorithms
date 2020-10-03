# Optimised School Method

 - Checks whether a Given Positive Integer is Prime or not.
 - Time Complexity:
	 - Worst Case Complexity:O(&Sqrt;n)
	 - Best Case Complexity:O(1)
	 - Average Case Complexity:O(&Sqrt;n)
- Worst Case Space Complexity:O(1)

### Logic

 1. Firstly We Only check till &Sqrt;n numbers from 3.
 2. We further Optimised the Algorithm by observing the pattern that all Prime Numbers are of the Form 6k ± 1 with exception of 1 and 2.
 3. We check whether all (i+6)<sup>th</sup> number are divisible by given number and iterate till the &Sqrt;n<sup>th</sup> number.
 4. Pseudo Code:
		

	    function is_prime(n)
	        if n ≤ 3 then
	            return n > 1
	        else if n mod 2 = 0 or n mod 3 = 0
	            return false
    
        let i ← 5
        while i × i ≤ n do
            if n mod i = 0 or n mod (i + 2) = 0
               return false
            i ← i + 6
    
        return true
