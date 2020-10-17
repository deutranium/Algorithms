'''COUNTINGSORT
Counting sort is a sorting technique based on keys between a specific range.
It works by counting the number of objects having distinct key values.
Then doing some arithmetic to calculate the position of each object in the
output sequence.''' 


def countSort(arr):
   output = [0 for i in range(256)]                                   
   count = [0 for i in range(256)]                    # Create a count array initialized with 0
   ans = ["" for _ in arr]                            # as strings are immutable

   for i in arr:
      count[ord(i)] += 1                              # position of character in the output array

      
   for i in range(256):
      count[i] += count[i-1]                          # output character array

  
   for i in range(len(arr)):
      output[count[ord(arr[i])]-1] = arr[i]
      count[ord(arr[i])] -= 1                         # array of sorted charcters

   
   for i in range(len(arr)):
      ans[i] = output[i]
   return ans



#TEST
arr = "Algorithms"
ans = countSort(arr)
print ("Sorted character array is "+str("".join(ans)))


