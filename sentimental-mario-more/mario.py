from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height < 9 and height > 0:
        break

# Prints a pyramid of user defined height
for i in range(1, height + 1):
    print(" " * (height - i), end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)