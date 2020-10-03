# Linear Search

 - Searches For an Element by Traversing through the entire list.
 - Time Complexity:
	 - Worst Case Complexity:O(n)
	 - Best Case Complexity:O(1)
	 - Average Case Complexity:O(n/2)
- Worst Case Space Complexity:O(1)

### Logic

 1. Iterate through Each Element and compare each Element till you find the element. 
 2. If element is found,return the index.
 3. Otherwise return -1 or False representing that element is not found. 
 4. Pseudo Code:	

	    function linear_search(list,n)
        let i ← 0
        while i < len(list)
            if element = n 
              return i
        return -1
	
###  Instruction for Running code:
 - C
	```
	gcc LinearSearch.c
	./a.out
	```

 - Cpp
	```
	g++ LinearSearch.cpp
	./a.out
	```
- JavaScript
	```
	node LinearSearch.js
	```
- Python
	```
	python3 LinearSearch.py
	```
