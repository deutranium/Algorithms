# Python3 code to demonstrate 
# to check if list is subset of other 
# using all() 

# initializing list 
test_list = [int(item) for item in input("Enter the first list items : ").split()]

sub_list = [int(item) for item in input("Enter the second list items : ").split()]



# using all() to 
# check subset of list 
flag = 0
if (all(x in test_list for x in sub_list)):
    flag = 1

# printing result 
if (flag):
    print("Yes, list is subset of other.")
else:
    print("No, list is not subset of other.")
