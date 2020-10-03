T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    maxglobal = -9999999999999999999
    max_here = 0
       
    for i in range(0, n): 
        max_here = max_here + a[i] 
        if (maxglobal < max_here): 
            maxglobal = max_here 
  
        if max_here < 0: 
            max_here = 0   
    print(maxglobal)