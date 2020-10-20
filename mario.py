from cs50 import get_int
while True:
    # - height, m - width 
    n = get_int("Height: ")
    m = n + 1
    if n >= 1 and n <= 8:
        break
for i in range(0, n, ): 
    hashes = i + 1
    spaces = m - hashes

    print(" " * (spaces - 1), end="")
    print("#" * hashes)