from cs50 import get_int
while True:
    # k - hight, j - width
    k = get_int("Height: ")
    j = k + 1
    if k > 0 or k < 8:
       break
    # For each row  
for i in range(0, k):
    #Printing hashes
    hash = i + 1
    print("#" * hash)
    #Printing spaces
    space = j - hash
    print("" * space, end="")