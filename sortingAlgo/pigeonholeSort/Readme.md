
# Pigeonhole Sort

 -Pigeonhole Sort is a sorting algorithm that is suitable for sorting lists of elements where the number of elements (n) and the number of possible key values (N) are approximately the same. It requires O(n + Range) time where n is number of elements in input array and ‘Range’ is number of possible values in array.
 - Worst-case Complexity:O(N+n)
 - Worst-case Space Complexity:O(N+n)

### Logic

 1.Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively. Also find range as **max-min+1**.
 2. Set up an array of initially empty “pigeonholes” the same size as of the range calculated above.
 3. Visit each element of the array and then put each element in its pigeonhole. An element **arr[i]** is put in hole at index **arr[i] – min**.
 4. Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.
 ### Pseudo Code:
  

		function pigeonhole_sort(a)

			let my_min ← min(a)
			let my_max ← max(a)
			let size ← my_max - my_min + 1	
			let holes ← [0] * size
			for x in a
				if x is  not integer
				return -1
				holes[x - my_min] += 1
			let i ← 0
			for count in (0,size)
			while holes[count] > 0:
				holes[count] -= 1
				a[i] ← count + my_min
				i += 1
###  Instruction for Running code:

  
- Cpp
  	```
	g++ pigeonholeSort.cpp  
	./a.out
	``` 
- Python
	```
	python3 piegeonholeSort.py
	```
