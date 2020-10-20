from cs50 import get_float

#Promting for an answer, n - change owed, c - amount of coins
while True:
    n = get_float("Change owed: ")
    if n >= 0:
        break

#Converting to cents
n = round(n * 100)
c = 0
while n > 0:
    if n >= 25:
        n -= 25
        c += 1
    elif n >= 10:
        n -= 10
        c += 1
    elif n >= 5:
        n -= 5
        c += 1
    elif n >= 1:
        n -= 1
        c += 1

#Printing number of coins used
print(c)