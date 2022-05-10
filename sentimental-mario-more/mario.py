from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height < 8 and height > 0:
        break

for i in range(height + 1):
    print(" " * (height - i), end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)



