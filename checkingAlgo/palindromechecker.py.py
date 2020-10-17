'''A palindrome is a word, number, phrase, or other sequence
of characters which reads the same backward as forward, such
as madam, racecar,2002.
In this code we are going to check whether the string or a
number inputted by the user is a palindrome or not.'''



def pnum(a):                 #function to check whether a number is palindrome or not
    s1=str(a)
    c=s1[::-1]
    if c==a:
        print("number is palindrome")
    else:
        print("number is not palindrome")


        
def strpal(a):               #function to check whether a string is palindrome or not
    m=a[::-1]
    if m==a:
        print("string is palindrome")
    else:
        print("string is not palindrome")



#testcase
while True:
    z=int(input("1. number palindrome\n2. string palindrome\n3. to exit the program=="))
    if z==1:
        a=input("number=")
        pnum(a)
    elif z==2:
        a=input("enter a string=")
        strpal(a)
    else:
        break


