def pigeonholeSort(a): 

    my_min = min(a) 
    my_max = max(a) 
    size = my_max - my_min + 1
  
    # our list of pigeonholes 
    holes = [0] * size 
  
    # Populate the pigeonholes. 
    for x in a: 
        assert type(x) is int, "Input Only Integers"
        holes[x - my_min] += 1
  
    # Put the elements back into the array in order. 
    i = 0
    for count in range(size): 
        while holes[count] > 0: 
            holes[count] -= 1
            a[i] = count + my_min 
            i += 1
#Get The Size of The Array             
print("Enter the Size of the Array :") 
n=int(input())
a=[]
#Get The Elements of The Array
for i in range(0,n):
    ele=int(input())
    a.append(ele)

print("Pigeon Hole Sorted order is : ", end = ' ') 
  
pigeonholeSort(a) 
          
for i in range(0, len(a)): 
    print(a[i], end = ' ')